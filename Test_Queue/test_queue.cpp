#include "../My_Queue/TQueue.h"

#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
  ASSERT_NO_THROW(TQueue<int> q(3));
}
TEST(TQueue, cant_create_queue_with_negative_size)
{
    ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, can_get_count)
{
    TQueue<int> q(5);
   
  

  EXPECT_EQ(0, q.Get_count());
}


TEST(TQueue, new_queue_is_empty)
{
    TQueue<int> q(5);

    int sostoyanie = q.Empty();

  EXPECT_EQ(1, sostoyanie);
}


TEST(TQueue, can_push_and_pop)
{
    TQueue<int> q(5);
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




TEST(TQueue, throws_when_use_pop_on_empty_queue)
{
    TQueue<int> q(5);
  ASSERT_ANY_THROW(q.Pop());
}

TEST(TQueue, throws_when_use_push_on_overflow_queue)
{
    TQueue<int> q(3);
    q.Push(1);
    q.Push(1);
    q.Push(1);
    ASSERT_ANY_THROW(q.Push(1));
}
TEST(TQueue, can_use_front_and_back)
{

    TQueue<int> q(3);
    q.Push(1);
    int b1, b2;
    ASSERT_NO_THROW(b1 = q.front());
    ASSERT_NO_THROW(b2 = q.back());
    EXPECT_EQ(b1, b2);

}
TEST(TQueue, throws_when_use_front_or_back_on_empty_queue)
{

    TQueue<int> q(3);
    ASSERT_ANY_THROW(q.front());
    ASSERT_ANY_THROW(q.back());
}

TEST(TQueue, return_true_when_use_Full_on_full_queue)
{
    TQueue<int> q(3);
    q.Push(1);
    q.Push(1);
    q.Push(1);
    bool b1 = q.Full();
    EXPECT_EQ(1, b1);
}
TEST(TQueue, return_false_when_use_Full_on_not_full_queue)
{
    TQueue<int> q(3);
    q.Push(1);
    q.Push(1);

   
    bool b1 = q.Full();
    EXPECT_EQ(0, b1);
}
TEST(TQueue, return_true_when_use_Empty_on_empty_queue)
{
    TQueue<int> q(3);
   
    bool b1 = q.Empty();
    EXPECT_EQ(1, b1);
}
TEST(TQueue, return_false_when_use_Empty_on_not_empty_queue)
{
    TQueue<int> q(3);
    q.Push(1);
    q.Push(1);

    bool b1 = q.Empty();
    EXPECT_EQ(0, b1);
}
TEST(TQueue, compratiom_of_two_equal_queues_is_return_true)
{
    TQueue<int> q(3);
    q.Push(1);
    q.Push(1);
    TQueue<int> q2(3);
    q2.Push(1);
    q2.Push(1);


    EXPECT_EQ(1, q == q2);
}
TEST(TQueue, compratiom_of_two_not_equal_queues_is_return_false)
{
    TQueue<int> q(3);
    q.Push(1);
    q.Push(2);
    TQueue<int> q2(3);
    q2.Push(1);
    q2.Push(1);


    EXPECT_EQ(1, q != q2);
}

