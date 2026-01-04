#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <chrono>
#include <fstream>
#include <sstream>

double c = 299792458.0;
double G = 6.67430e-11;

struct Engine {
    GLFWwindow* window;
    int WIDTH = 800;
    int HEIGHT = 600;
    float width = 1e11;
    float height = 7.5e10;

    Engine () {
        if (!glfwInit()) {
            std::cerr << "GLFW failed to init!\n";
            exit(EXIT_FAILURE);
        }
        window = glfwCreateWindow(WIDTH, HEIGHT, "Black Hole Simulator", NULL, NULL);
        if (!window) {
            std::cerr << "Failed to create window!\n";
            exit(EXIT_FAILURE);
        }
        glViewport(0, 0, WIDTH, HEIGHT);
        glfwMakeContextCurrent(window);
    }


    void run() {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        double left = -width;
        double right = width;
        double bottom = -height;
        double top = height;
        glOrtho(left, right, bottom, top, -1.0, 1.0);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
} engine;

struct BlackHole {
    glm::vec2 position;
    double mass;
    double r_s;
    
    BlackHole (glm::vec2 pos, double m) : position(pos), mass(m) {
        r_s = (2.0 * G * mass) / (c*c); //https://en.wikipedia.org/wiki/Schwarzschild_radius
    }

    void draw() {
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(position.x, position.y);
        for (int i = 0; i <= 100; i++) {
            float angle = 2.0f * M_PI * i / 100;
            float x = cos(angle) * r_s + position.x;
            float y = sin(angle) * r_s + position.y;
            glVertex2f(x, y);
        }
        glEnd();
    }
} SagA(glm::vec2(0.0, 0.0), 8.54e36);

struct Ray {
    double x, y;
    double r, phi;
    double dr, dphi;
    double d2r, d2phi;

    glm::vec2 dir;
    
    std::vector<glm::vec2> trail;

    Ray (glm::vec2(pos), glm::vec2(dir)) : x(pos.x), y(pos.y), dir(dir) {
        r = hypot(x, y);
        phi = atan2(y, x);
        dr = c * cos(phi) + dir.y * sin(phi);
        dphi = (-c * sin(phi) + dir.y * cos(phi)) / r;
        d2r = 0.0;
        d2phi = 0.0;
    }

    void draw() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glLineWidth(5.0f);
        size_t N = trail.size();
        if (N < 2) return;

        glBegin(GL_LINE_STRIP);
        for (size_t i = 0; i < N; i++) {
            float alpha = float(i) / float(N-1);
            glColor4f(1.0, 1.0, 1.0, std::max(alpha, 0.05f));
            glVertex2f(trail[i].x, trail[i].y);
        }
        glVertex2f(x, y);
        glEnd();
    }

    void step(double dt) {
        if (r < SagA.r_s) return;

        // dr = c * cos(phi) + dir.y * sin(phi) + d2r;
        // dphi = (-c * sin(phi) + dir.y * cos(phi)) / r + d2phi;


        r += dr * dt;
        phi += dphi * dt;

        x = cos(phi) * r;
        y = sin(phi) * r;
        trail.push_back(glm::vec2(x,y));
    }
};

std::vector<Ray> rays;

void geodesic(Ray& ray) {
    double r = ray.r;
    double phi = ray.phi;
    double dr = ray.dr;
    double dphi = ray.dphi;

    ray.dr += r * dphi * dphi - (c * c * SagA.r_s) / (2.0 * r * r); //derivation by https://www.youtube.com/watch?v=8-B6ryuBkCM

    ray.dphi += -2.0 * dr * dphi / r;
}

int main() {
    for (float y = -engine.height; y < engine.height; y += 1e10)
        rays.push_back(Ray(glm::vec2(-engine.width, y), glm::vec2(1.0, 0.0)));

    while(!glfwWindowShouldClose(engine.window)) {
        engine.run();
        SagA.draw();

        for (auto& ray : rays) {
            geodesic(ray);
            ray.draw();
            ray.step(1);
        }

        glfwSwapBuffers(engine.window);
        glfwPollEvents();
    }
    return 0;
}