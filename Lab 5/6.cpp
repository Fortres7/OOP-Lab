#include <iostream>
using namespace std;

class GraphicsRenderer {
public:
    void render() {
        cout << "Rendering graphics\n";
    }
};

class InputHandler {
public:
    void processInput() {
        cout << "Processing user input\n";
    }
};

class PhysicsEngine {
public:
    void update() {
        cout << "Updating physics\n";
    }
};

class GameEngine {
private:
    GraphicsRenderer graphics;
    InputHandler input;
    PhysicsEngine physics;

public:
    void run() {
        cout << "Starting Game Engine...\n";
        input.processInput();
        physics.updatePhysics();
        graphics.render();
        cout << "Game executed successfully\n";
    }
};

int main() {
    GameEngine game;
    game.run(); 
    return 0;
}
