#include <thread>
#include <atomic>
#include <random>
#include <iostream>
#include <chrono>
#include <cmath>

#define EPS 1
#define DT 0.016 //~60FPS
using namespace std;

class Bullet {
private:
    double x, y;
    double destX, destY;
    double speed;
    atomic<bool> finished{false};
    thread worker;

    double distance() const {
        double dx = destX - x;
        double dy = destY - y;
        return sqrt(pow(dx, 2) + pow(dy,2));
    }

    void step() {
        if (distance() < EPS) {
            finished = true;
            return;
        }

        double dx = destX - x;
        double dy = destY - y;
        double dist = distance();
        double moveX = (dx / dist) * speed * DT;
        double moveY = (dy / dist) * speed * DT;

        x += moveX;
        y += moveY;

        cout << "Bullet at x: " << x << " y: " << y << " -> dx: " << destX << " dy: " << destY << " moveX: " << moveX << " moveY: " << moveY << endl;
    }

    void run() {
        using namespace std::literals::chrono_literals;
        while (!finished) {
            step();
            this_thread::sleep_for(16ms); //~60FPS
        }
        cout << "Bullet hit!\n";
    }

public:
    Bullet (double startX, double startY, double destX, double destY, double speed) : x(startX), y(startY), destX(destX), destY(destY), speed(speed)  {
        worker = thread(&Bullet::run, this);
    }

    Bullet(Bullet&& other) noexcept : x(other.x), y(other.y), destX(other.destX), destY(other.destY), speed(other.speed), worker(std::move(other.worker)) {}
    Bullet& operator=(Bullet&& other) noexcept {
        if (this != &other) {
            if (worker.joinable()) {
                worker.join();
            }
            x = other.x;
            y = other.y;
            destX = other.destX;
            destY = other.destY;
            speed = other.speed;
            worker = std::move(other.worker);
        }
        return *this;
    }
    
    Bullet(const Bullet&) = delete;
    Bullet& operator=(const Bullet&) = delete;

    void join() {
        if (worker.joinable()) {
            worker.join();
        }
    }

    ~Bullet() {
        finished = true;
        if (worker.joinable()) {
            worker.join();
        }
    }

    bool isFinished() const {return finished;}
};

int main() {
    vector<Bullet> bullets;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> posDist(-100, 100);
    uniform_int_distribution<> speedDist(10,50);
    const int NUM_BULLETS = 10;

    cout << "Launch " << NUM_BULLETS << " bullets\n\n";

    for (int i = 0; i < NUM_BULLETS; i++) {
        double sx = posDist(gen), sy = posDist(gen);
        double dx = posDist(gen), dy = posDist(gen);
        double speed = speedDist(gen);

        bullets.emplace_back(sx,sy,dx,dy,speed);
    }
    cout << "\nWaiting for all bullet to reach its destinations\n";
    for (auto& b : bullets) {
        b.join();
    }
    cout << "All bullet destroyed.\n";
    return 0;
}