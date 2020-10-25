#include <string>
#include "player.hpp"

Player::Player() {
	name_ = "";
	mark_ = "";
	age_ = 0;
}

Player::~Player() {
	name_ = "";
	mark_ = "";
	age_ = 0;
}

Player::Player(std::string& name, std::string& mark, int &age) {
	name_ = name;
	mark_ = mark;
	age_ = age;
}

std::string Player::getName() const {
	return name_;
}

std::string Player::getMark() const {
	return mark_;
}