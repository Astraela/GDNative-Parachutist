#ifndef Points_H
#define Points_H

#include <Godot.hpp>
#include <RichTextLabel.hpp>

namespace godot {

class Points : public RichTextLabel {
    GODOT_CLASS(Points, RichTextLabel)

private:
    int points = 0;

public:
    static void _register_methods();

    void _init(); 

    void AddOne();
};

}

#endif