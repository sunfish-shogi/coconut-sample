//
//  Array2d.h
//
//  Created by Kubo Ryosuke on 13/08/16.
//
//

#ifndef __coconut_sample_Array2d__
#define __coconut_sample_Array2d__

#include "Position.h"
#include <vector>
#include <cassert>

namespace coconut_sample {
	
	template<class T>
	class Array2d {
	private:
		
		std::vector<T> array;
		int width;
		int height;
		
		int getIndex(int x, int y) const {
			assert(isValid(x, y));
			return x + y * width;
		}
		
	public:
		
		class Array {
		private:
			
			Array2d<T>& array2d;
			int x;
			
		public:
			
			Array(const Array& array) : array2d(array.array2d), x(array.x) {
			}
			explicit Array(Array2d<T>& array2d, int x) : array2d(array2d), x(x) {
			}
			
			T& operator[](int y) {
				return array2d.get(x, y);
			}
			const T& operator[](int y) const {
				return array2d.get(x, y);
			}
			
		};
		
		Array2d() : width(0), height(0) {
		}
		explicit Array2d(int width, int height) :
				width(width), height(height), array(width*height) {
		}
		explicit Array2d(int width, int height, const T src) :
				width(width), height(height), array(width*height, src) {
		}
		
		void resize(int width, int height) {
			this->width = width;
			this->height = height;
			array.resize(width * height);
		}
		void resize(int width, int height, const T src) {
			this->width = width;
			this->height = height;
			array.resize(width * height, src);
		}
		
		T& get(int x, int y) {
			return array[getIndex(x, y)];
		}
		const T& get(int x, int y) const {
			return array[getIndex(x, y)];
		}
		T& get(const Position& pos) {
			return array[getIndex(pos.x, pos.y)];
		}
		const T& get(const Position& pos) const {
		return array[getIndex(pos.x, pos.y)];
		}
		
		Array operator[](int x) {
			return Array(*this, x);
		}
		const Array operator[](int x) const {
			return Array(*this, x);
		}
		
		bool isValid(int x, int y) const {
			return x >= 0 && x < width && y >= 0 && y < height;
		}
		bool isValid(const Position& pos) const {
			return isValid(pos.x, pos.y);
		}
		
	};
	
}

#endif /* defined(__coconut_sample_Array2d__) */
