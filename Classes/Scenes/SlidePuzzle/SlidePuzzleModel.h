//
//  SlidePuzzleModel.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#ifndef __coconut_sample__SlidePuzzleModel__
#define __coconut_sample__SlidePuzzleModel__

#include "Array2d/Array2d.h"
#include <coconut/EventEmitter.hpp>
#include <coconut/schedule/ScheduleManager.h>

#define EMPTY_PIECE								Position::INVALID_POSITION
#define IS_EMPTY(piece)						(!(bool)piece)

namespace coconut_sample {
	
	enum class SlidePuzzleStatus {
		INIT,
		SHUFFLE,
		PLAY,
		COMPLETE,
	};

	class SlidePuzzleModel {

		// event emitters
		DEFINE_EVENT_EMITTER(Reset);
		DEFINE_EVENT_EMITTER_WITH_ARG(Set, const Position&);
		DEFINE_EVENT_EMITTER_WITH_ARG(Slide, const Position&);
		DEFINE_EVENT_EMITTER(Complete);

	private:
		
		SlidePuzzleStatus _status;
		int _width;
		int _height;
		Array2d<Position> _pieces;
		Position _emptyPos;
		int _shuffleCount;
		bool _shuffleHorizontal;
		
		coconut::ScheduleManager _scheduleManager;
		const coconut::Schedule* _scheduleShuffle;
		
		bool slideForce(const Position& pos);
		void slide(const Position& endPos, Direction dir);
		void shuffleProc();
		void check();
		bool isCompleted();

	public:

		SlidePuzzleModel();
		virtual ~SlidePuzzleModel();
		void init();
		
		SlidePuzzleStatus getStatus() const {
			return _status;
		}
		int getWidth() const {
			return _width;
		}
		int getHeight() const {
			return _height;
		}
		const Array2d<Position> getPieces() const {
			return _pieces;
		}
		void reset();
		bool slide(const Position& pos);
		void shuffle();

	};

}

#endif /* defined(__coconut_sample__SlidePuzzleModel__) */
