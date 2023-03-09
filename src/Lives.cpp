#include <Godot.hpp>
#include <Viewport.hpp>
#include <SceneTree.hpp>
#include <Node2D.hpp>
#include <RichTextLabel.hpp>
#include <memory>
#include <String.hpp>
#include <set>
#include "Lives.h"

using namespace godot;

void Lives::_register_methods()
{
    register_method("Hurt", &Lives::Hurt);
}

void Lives::_init() {}

void Lives::Hurt()
{
    lives -= 1;

    String text = "[right]" + String::num_int64(lives) + " LIVES[/right]";
    set_bbcode(text);
    if (lives < 0){
        Array nodes = get_tree()->get_nodes_in_group("Parachutists");
        for (int i = 0; i < nodes.size(); i++) {
            Object::cast_to<Node>(nodes[i])->queue_free();
        }
        get_tree()->change_scene("res://GameOver.tscn");
    }
}