//
//  Position.h
//
//  Created by Kubo Ryosuke on 13/08/16.
//
//

#ifndef __coconut_sample_Position_h__
#define __coconut_sample_Position_h__

namespace coconut_sample {
	
	enum class Direction {
		LEFT, RIGHT, UP, DOWN,
	};
	
	inline Direction reverse_dir(Direction dir) {
		switch(dir) {
			case Direction::LEFT: return Direction::RIGHT;
			case Direction::RIGHT: return Direction::LEFT;
			case Direction::UP: return Direction::DOWN;
			case Direction::DOWN: return Direction::UP;
		}
	}
	
	class Position {
	public:
		
		static const Position INVALID_POSITION;
		
		int x;
		int y;
		bool valid;
		
		Position() : valid(true) {
		}
		Position(const Position& pos) : x(pos.x), y(pos.y), valid(pos.valid) {
		}
		explicit Position(int x, int y, bool valid = true)
				: x(x), y(y), valid(valid) {
		}
		explicit Position(bool valid) : valid(valid) {
		}
		
		Position up(int distance = 1) const {
			return Position(x, y + distance, valid);
		}
		Position down(int distance = 1) const {
			return Position(x, y - distance, valid);
		}
		Position left(int distance = 1) const {
			return Position(x - distance, y, valid);
		}
		Position right(int distance = 1) const {
			return Position(x + distance, y, valid);
		}
		Position at(Direction dir, int distance = 1) const {
			switch (dir) {
				case Direction::LEFT: return left(distance);
				case Direction::RIGHT: return right(distance);
				case Direction::UP: return up(distance);
				case Direction::DOWN: return down(distance);
				default: return INVALID_POSITION;
			}
		}
		
		bool operator==(const Position& obj) const {
			return valid && obj.valid && x == obj.x && y == obj.y;
		}
		bool operator!=(const Position& obj) const {
			return !operator==(obj);
		}
		operator bool() const {
			return valid;
		}
		
	};
	
};

#endif //__coconut_sample_Position_h__
