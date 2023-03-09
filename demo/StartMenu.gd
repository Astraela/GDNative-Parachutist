extends Node

#Play
func _on_Button_pressed():
	get_tree().change_scene("res://Parachute.tscn")

#Quit
func _on_Button2_pressed():
	get_tree().quit()
