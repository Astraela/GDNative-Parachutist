#ifndef Parachutist_H
#define Parachutist_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <RandomNumberGenerator.hpp>

namespace godot {

class Parachutist : public Node2D {
    GODOT_CLASS(Parachutist, Node2D)

private:
    float fallingSpeed = 8.0; // basicaly equal to falling
    float rotationSway = 30; //max degree you rotate
    float rotationSpeed = 0.8f; //speed at which you rotate
    float positionSpeed = -4.0f; //additional horizontal speed depending on which side you're rotated to
    float randomHorizontalSpeed = 0; 
    float maxHorSpeed = 10;
    Vector2 velocity = Vector2(0, 0);
    godot::Ref<godot::RandomNumberGenerator> _random;

public:
    static void _register_methods();

    void _init();

    void _process(float delta);
    void _ready();
};

}

#endif