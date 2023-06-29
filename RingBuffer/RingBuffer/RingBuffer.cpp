#include "RingBuffer.h"

#include <iostream>
#include <string.h>

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
	head = nullptr;
	rear = nullptr;
	delete[] data;
	data = nullptr;
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
				memcpy(data, addData + _capacity - (rear - 1 - data), (dataLength + (_capacity - (rear - 1 - data))) % _capacity);
				rear = data + (dataLength - (_capacity - (rear - 1 - data)));
			}
			else
			{
				memcpy(rear - 1, addData, dataLength);
				rear += dataLength - 1;
			}
		}
	}
	_size += dataLength - 1;
	this->printData();
}

void RingBuffer::pop(char* outStr, const size_t dataLength)
{
	if (_size != 0)
	{
		auto temp = '\0';
		if (_size < dataLength)
		{
			auto bTailSizeEnough = _capacity - (head - data);
			if (bTailSizeEnough < _size)
			{
				memcpy(outStr, head, bTailSizeEnough);
				memcpy(outStr + bTailSizeEnough, data, _size - bTailSizeEnough - 1);
				memcpy(data, &temp, _capacity);
			}
			else
			{
				memcpy(outStr, head, _size);
				memcpy(data, &temp, _capacity);
			}
			head = rear;
			rear = data + (head - data + 1) % _capacity;
			// memcpy(head, &temp, 1);
			memcpy(outStr + _size, &temp, 1);
		}
		else
		{
			auto bTailSizeEnough = _capacity - (head - data);
			if (bTailSizeEnough < dataLength)
			{
				memcpy(outStr, head, bTailSizeEnough);
				memcpy(head, &temp, bTailSizeEnough);
				memcpy(outStr + bTailSizeEnough, data, dataLength - bTailSizeEnough);
				memcpy(data, &temp, dataLength - bTailSizeEnough);
				head = data + (dataLength - bTailSizeEnough);
			}
			else
			{
				memcpy(outStr, head, dataLength);
				memcpy(head, &temp, dataLength);
				head = data + ((head - data) + dataLength) % _capacity;
			}
			memcpy(outStr + dataLength - 1, &temp, 1);
		}
		if (_size < dataLength)
		{
			_size = 0;
		}
		else
		{
			_size -= dataLength;
		}
	}
	else
		outStr = nullptr;

	this->printData();
}
