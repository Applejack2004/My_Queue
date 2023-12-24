#include "../My_Queue/TQueue.h"

#include "gtest.h"

TEST(TLQueue, can_create_queue_with_positive_size)
{
  ASSERT_NO_THROW(TLQueue<int> q);
}


TEST(TLQueue, can_get_count)
{
    TLQueue<int> q;
   
  

  EXPECT_EQ(0, q.ElementsNumber());
}


TEST(TLQueue, new_queue_is_empty)
{
    TLQueue<int> q;

    int sostoyanie = q.empty();

  EXPECT_EQ(1, sostoyanie);
}


TEST(TLQueue, can_push_and_pop)
{
    TLQueue<int> q;
    int a1 = 1;
    int a2 = 2;
    int a3 = 3;
    ASSERT_NO_THROW(q.Push(a1));

    ASSERT_NO_THROW(q.Push(a2));
    ASSERT_NO_THROW(q.Push(a3));
    int b1, b2, b3;
    ASSERT_NO_THROW( b1 = q.Pop());
    ASSERT_NO_THROW( b2 = q.Pop());
    ASSERT_NO_THROW( b3 = q.Pop());
    EXPECT_EQ(a1, b1); 
    EXPECT_EQ(a2, b2);
    EXPECT_EQ(a3, b3);

   
}




TEST(TLQueue, throws_when_use_pop_on_empty_queue)
{
    TLQueue<int> q;
  ASSERT_ANY_THROW(q.Pop());
}



TEST(TLQueue, can_use_front_and_back)
{

    TLQueue<int> q;
    q.Push(1);
    int b1, b2;
    ASSERT_NO_THROW(b1 = q.Front());
    ASSERT_NO_THROW(b2 = q.Back());
    EXPECT_EQ(b1, b2);

}
TEST(TLQueue, throws_when_use_front_or_back_on_empty_queue)
{

    TLQueue<int> q;
    ASSERT_ANY_THROW(q.Front());
    ASSERT_ANY_THROW(q.Back());
}

TEST(TLQueue, can_copy_Queue)
{
    TLQueue<int> q;
    q.Push(1);
    q.Push(1);
    q.Push(1);
    ASSERT_NO_THROW(TLQueue<int> q2(q));
    TLQueue<int> q2(q);
   
    EXPECT_EQ(1, q==q2);
}
TEST(TLQueue, return_false_when_use_Full_on_not_full_queue)
{
    TLQueue<int> q;
    q.Push(1);
    q.Push(1);

   
    bool b1 = q.Full();
    EXPECT_EQ(0, b1);
}
TEST(TLQueue, return_true_when_use_Empty_on_empty_queue)
{
    TLQueue<int> q;
   
    bool b1 = q.empty();
    EXPECT_EQ(1, b1);
}
TEST(TLQueue, return_false_when_use_Empty_on_not_empty_queue)
{
    TLQueue<int> q;
    q.Push(1);
    q.Push(1);

    bool b1 = q.empty();
    EXPECT_EQ(0, b1);
}
TEST(TLQueue, comparison_of_two_equal_queues_is_return_true)
{
    TLQueue<int> q;
    q.Push(1);
    q.Push(1);
    TLQueue<int> q2;
    q2.Push(1);
    q2.Push(1);


    EXPECT_EQ(1, q == q2);
}
TEST(TLQueue, compratiom_of_two_not_equal_queues_is_return_false)
{
    TLQueue<int> q;
    q.Push(1);
    q.Push(2);
    TLQueue<int> q2;
    q2.Push(1);
    q2.Push(1);


    EXPECT_EQ(1, q != q2);
}

