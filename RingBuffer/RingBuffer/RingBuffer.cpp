#include "RingBuffer.h"

RingBuffer::RingBuffer(const size_t memorySize)
{
	_size = 0;
	_capacity = memorySize;
	data = new char[_capacity];
	head = data;
	rear = head + 1;
}

RingBuffer::~RingBuffer()
{
	delete data;
	data = nullptr;
	head = nullptr;
	rear = nullptr;
}

void RingBuffer::push(const char* addData, const size_t dataLength)
{
	auto oldHeadPos = head - data;
	auto oldRearPos = rear - data;
	if (_capacity - _size < dataLength)
	{
		char* tmp = data;
		auto oldCapacity = _capacity;
		_capacity += dataLength * 2;
		data = new char[_capacity];
		if (rear - head < 0)
		{
			memcpy(data, head, oldCapacity - oldHeadPos + 1);
			rear = data + (oldCapacity - oldHeadPos + 1);
			memcpy(rear, tmp, oldRearPos);
			rear += oldRearPos;
			memcpy(rear - 1, addData, dataLength);
			rear += dataLength - 1;
			head = data;
		}
		else
		{
			memcpy(data, tmp, _size);
			head = data;
			rear = head + _size;
			memcpy(rear - 1, addData, dataLength);
			rear += dataLength - 1;
		}
		delete tmp;
		tmp = nullptr;
	}
	else
	{
		if (rear - head < 0)
		{
			memcpy(rear - 1, addData, dataLength);
			rear += dataLength - 1;
		}
		else
		{
			if (_capacity - (rear - data) < dataLength)
			{
				memcpy(rear - 1, addData, _capacity - (rear - 1 - data));
				rear = data;
				memcpy(rear, addData + _capacity - (rear - 1 - data), dataLength - (_capacity - (rear - 1 - data)));
				rear += dataLength - (_capacity - (rear - 1 - data));
			}
			else
			{
				memcpy(rear - 1, addData, dataLength);
				rear += dataLength - 1;
			}
		}
	}
	_size += dataLength;
}

void RingBuffer::pop(char* outStr, const size_t dataLength)
{
	if (_size < dataLength)
	{
		memcpy(data, nullptr, _capacity);
		head = rear;
	}
	else
	{
		auto bTailSizeEnough = _capacity - (head - data);
		if (bTailSizeEnough < dataLength)
		{

		}
	}
}
