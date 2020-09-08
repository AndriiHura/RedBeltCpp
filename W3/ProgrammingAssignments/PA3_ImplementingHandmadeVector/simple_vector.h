#pragma once

#include <cstdlib>

template <typename T>
class SimpleVector {
public:
	SimpleVector() {
		data_ = nullptr;
		size_ = 0;
		capacity_ = 0;
	}

	explicit SimpleVector(size_t size) {
		data_ = new T[size];
		size_ = size;
		capacity_ = size;
	}

	~SimpleVector() {
		delete[] data_;
	}

	T& operator[](size_t index) {
		return data_[index];
	}

	const T& operator[](size_t index) const {
		return data_[index];
	}

	const T* begin() const { return data_; }

	const T* end() const { return data_ + size_; }

	T* begin() { return data_; }

	T* end() { return data_ + size_;}

	size_t Size() const {
		return size_;
	}
	size_t Capacity() const {
		return capacity_;
	}

	void PushBack(const T& value) {
		if (data_ == nullptr) {
			data_ = new T[1];
			size_ = 1;
			capacity_ = 1;
			data_[0] = value;
			return;
		}

		if (size_ == capacity_) {
			T* tmp = new T[size_ + 1];
			for (int i = 0; i < size_; ++i) {
				tmp[i] = data_[i];
			}
			tmp[size_] = value;
			delete[] data_;

			data_ = new T[capacity_ * 2];
			for (int i = 0; i < size_; ++i) {
				data_[i] = tmp[i];
			}
			data_[size_] = value;
			delete[] tmp;
			capacity_ *= 2;
			++size_;
		}
		else {
			data_[size_] = value;
			++size_;
		}


	}

private:
	T* data_;
	size_t size_;
	size_t capacity_;
};
