#pragma once
class RingBuffer
{
public:
	RingBuffer() = default;
	RingBuffer(const size_t memorySize);
	~RingBuffer();

	void push(const char* addData, const size_t dataLength);
	void pop(char* outStr, const size_t dataLength);

private:
	char* data;
	char* head;
	char* rear;
	size_t _size;
	size_t _capacity;
};