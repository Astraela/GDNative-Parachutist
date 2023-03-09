#include <Godot.hpp>
#include <Viewport.hpp>
#include <SceneTree.hpp>
#include <Node2D.hpp>
#include <RichTextLabel.hpp>
#include <memory>
#include <String.hpp>
#include <set>
#include "points.h"

using namespace godot;

void Points::_register_methods()
{
    register_method("AddOne", &Points::AddOne);
}

void Points::_init() {}

void Points::AddOne()
{
    Godot::print("AddOne");
    points += 1;

    String text = "[right]" + String::num_int64(points) + " POINTS[/right]";
    set_bbcode(text);
}