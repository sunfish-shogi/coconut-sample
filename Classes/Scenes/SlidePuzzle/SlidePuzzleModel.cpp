//
//  SlidePuzzleModel.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#include "SlidePuzzleModel.h"
#include <coconut/random/Random.h>

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	SlidePuzzleModel::SlidePuzzleModel() {
	}

	SlidePuzzleModel::~SlidePuzzleModel() {
	}

	void SlidePuzzleModel::init() {
		_width = 4;
		_height = 4;
	}

	void SlidePuzzleModel::reset() {
		_status = SlidePuzzleStatus::INIT;
		
		_scheduleManager.clear();
		
		_pieces.resize(_width, _height);
		for (int x = 0; x < _width; x++) {
			for (int y = 0; y < _height; y++) {
				Position pos(x, y);
				_pieces.get(pos) = Position(pos);
			}
		}
		_emptyPos = Position(_width-1, 0);
		_pieces.get(_emptyPos) = EMPTY_PIECE;
		
		emitReset();
		
		for (int x = 0; x < _width; x++) {
			for (int y = 0; y < _height; y++) {
				Position piece = _pieces.get(x, y);
				if (!IS_EMPTY(piece)) {
					emitSet(piece);
				}
			}
		}
		
		_scheduleManager.clear();
		shuffle();
	}
	
	bool SlidePuzzleModel::slide(const Position& pos) {
		if (_status != SlidePuzzleStatus::PLAY) {
			return false;
		}
		return slideForce(pos);
	}
	
	bool SlidePuzzleModel::slideForce(const Position& pos) {
		if (!_pieces.isValid(pos)) {
			return false;
		}
		if (pos.x == _emptyPos.x) {
			if (pos.y > _emptyPos.y) {
				slide(pos, Direction::UP);
				return true;
			} else if (pos.y < _emptyPos.y) {
				slide(pos, Direction::DOWN);
				return true;
			}
			return false;
		} else if (pos.y == _emptyPos.y) {
			if (pos.x > _emptyPos.x) {
				slide(pos, Direction::RIGHT);
				return true;
			} else if (pos.x < _emptyPos.x) {
				slide(pos, Direction::LEFT);
				return true;
			}
			return false;
		}
		return false;
	}
	
	void SlidePuzzleModel::slide(const Position& endPos, Direction dir) {
		for (Position pos = _emptyPos; pos != endPos; pos = pos.at(dir)) {
			_pieces.get(pos) = _pieces.get(pos.at(dir));
			emitSlide(pos);
		}
		_emptyPos = endPos;
		_pieces.get(endPos) = EMPTY_PIECE;
		check();
	}

	void SlidePuzzleModel::shuffle() {
		_status = SlidePuzzleStatus::SHUFFLE;
		_shuffleCount = 0;
		_shuffleHorizontal = false;
		_scheduleShuffle = _scheduleManager.scheduleForever(0.15f, 1.0f, [this]() {
			shuffleProc();
		});
	}
	
	void SlidePuzzleModel::shuffleProc() {
		if (_shuffleHorizontal) {
			RandomInt r(0, _width - 2);
			int x = r();
			if (x >= _emptyPos.x) { x++; }
			slideForce(Position(x, _emptyPos.y));
		} else {
			RandomInt r(0, _height - 2);
			int y = r();
			if (y >= _emptyPos.y) { y++; }
			slideForce(Position(_emptyPos.x, y));
		}
		_shuffleCount++;
		_shuffleHorizontal = !_shuffleHorizontal;
		if (_shuffleCount >= 50 && !isCompleted()) {
			_scheduleManager.cancel(_scheduleShuffle);
			_status = SlidePuzzleStatus::PLAY;
		}
	}

	void SlidePuzzleModel::check() {
		if (_status == SlidePuzzleStatus::PLAY && isCompleted()) {
			_status = SlidePuzzleStatus::COMPLETE;
			emitComplete();
		}
	}
	
	bool SlidePuzzleModel::isCompleted() {
		for (int x = 0; x < _width; x++) {
			for (int y = 0; y < _height; y++) {
				Position pos(x, y);
				Position piece = _pieces.get(pos);
				if (!IS_EMPTY(piece) && piece != pos) {
					return false;
				}
			}
		}
		return true;
	}
	
}
