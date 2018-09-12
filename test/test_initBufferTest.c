#include "unity.h"
#include "ringbuffer.h"

#define BUFFER_SIZE 256

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Init_Buffer_Size_multiple_of_2()
{     
   RingBuffer buffer;
   uint8_t data[128];
   TEST_ASSERT_EQUAL_INT(ringBufferInit(&buffer, data, BUFFER_SIZE), 1);
   TEST_ASSERT_EQUAL_INT(0xFF, buffer.sizeMask);
   TEST_ASSERT_EQUAL_INT(buffer.tail, 0);
   TEST_ASSERT_EQUAL_INT(buffer.head, 0);
   TEST_ASSERT_EQUAL_PTR(buffer.data, data);
}

void test_Init_Buffer_Size_Not_multiple_of_2()
{     
   RingBuffer buffer;
   uint8_t data[128];
   TEST_ASSERT_EQUAL_INT(ringBufferInit(&buffer, data, 126), 0);
}