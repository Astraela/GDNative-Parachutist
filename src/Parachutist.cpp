#include <Godot.hpp>
#include <Viewport.hpp>
#include <SceneTree.hpp>
#include <Node2D.hpp>
#include <RandomNumberGenerator.hpp>
#include <memory>
#include <set>
#include "Parachutist.h"
#include "Lives.h"

using namespace godot;

void Parachutist::_register_methods()
{
    register_method("_process", &Parachutist::_process);
    register_method("_ready", &Parachutist::_ready);
}

void Parachutist::_init() {
}

void Parachutist::_ready()
{
    _random = (godot::Ref<godot::RandomNumberGenerator>)godot::RandomNumberGenerator::_new();
    _random->randomize();
    float nr = _random->randf_range(-1, 1);
    randomHorizontalSpeed = nr * maxHorSpeed;
}

void Parachutist::_process(float delta) {
    Vector2 acceleration = Vector2(positionSpeed + randomHorizontalSpeed, fallingSpeed);
    Vector2 friction = Vector2(0.1f, 0.075f) * velocity;
    acceleration -= friction;

    velocity += acceleration;
    Vector2 screensize = get_viewport_rect().size;
    Vector2 position = get_position();
    if (position.x >= screensize.x - 10 && randomHorizontalSpeed > 0) {
        randomHorizontalSpeed *= -1;
    }
    else if (position.x <= 0 + 10 && randomHorizontalSpeed < 0) {
        randomHorizontalSpeed *= -1;
    }
    set_rotation_degrees(get_rotation_degrees() + rotationSpeed);
    if ((get_rotation_degrees() < -rotationSway && rotationSpeed < 0) || (get_rotation_degrees() > rotationSway && rotationSpeed > 0)) {
        rotationSpeed *= -1;
        positionSpeed *= -1;
    }
    set_position(position + velocity * delta);
    if (position.y > get_viewport_rect().size.y) {
        Node* node = Node2D::get_tree()->get_root()->get_node("Node2D/UI/Lives");
        Lives* lives = cast_to<Lives>(node);
        lives->Hurt();
        queue_free();
    }
}