#ifndef __DATA_H__
#define __DATA_H__

class Data
{
public:
	static const Data Null;

	Data();
	Data(const Data& other);
	Data(Data&& other);
	~Data();

	Data& operator= (const Data& other);
	Data& operator= (Data&& other);

	unsigned char* getBytes() const;

	size_t getSize() const;

	void copy(unsigned char* bytes, const size_t size);

	void fastSet(unsigned char* bytes, const size_t size);

	void clear();

	bool isNull() const;

	unsigned char* takeBuffer(size_t* size);

private:
	void move(Data& other);

private:
	unsigned char* _bytes;
	size_t _size;
};


#endif // __DATA_H__
