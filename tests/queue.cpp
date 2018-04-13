#include <catch.hpp>
#include <sstream>

#include "queue.hpp"

TEST_CASE("creating_tree")
{
	queue_t<int> q;
	REQUIRE( q.head_() == nullptr );
	REQUIRE( q.tail_() == nullptr );
}

TEST_CASE("push and pop int")
{
	queue_t<int> q;
	
	q.push(3);
	REQUIRE( q.head__(q.head_()) == 3 );
	REQUIRE( q.tail__(q.tail_()) == 3 );
	
	q.push(6);
	REQUIRE( q.head__(q.head_()) == 3 );
	REQUIRE( q.tail__(q.tail_()) == 6 );
	
	q.push(9);
	REQUIRE( q.head__(q.head_()) == 3 );
	REQUIRE( q.tail__(q.tail_()) == 9 );
	
	REQUIRE( q.pop() == 3 );
	REQUIRE( q.pop() == 6 );
	REQUIRE( q.pop() == 9 );
}

TEST_CASE("push and pop double")
{
	queue_t<double> q;
	
	q.push(3.3);
	REQUIRE( q.head__(q.head_()) == 3.3 );
	REQUIRE( q.tail__(q.tail_()) == 3.3 );
	
	q.push(6.6);
	REQUIRE( q.head__(q.head_()) == 3.3 );
	REQUIRE( q.tail__(q.tail_()) == 6.6 );
	
	q.push(9.9);
	REQUIRE( q.head__(q.head_()) == 3.3 );
	REQUIRE( q.tail__(q.tail_()) == 9.9 );
	
	REQUIRE( q.pop() == 3.3 );
	REQUIRE( q.pop() == 6.6 );
	REQUIRE( q.pop() == 9.9 );
}

TEST_CASE("throw")
{
	queue_t<int> q;
	REQUIRE_THROWS_AS( q.pop() , std::logic_error);
}

TEST_CASE("copy")
{
	queue_t<int> q1;
	q1.push(3);
	q1.push(6);
	q1.push(9);
	queue_t<int> q2 = q1;
	int sum = q2.pop();
	sum = sum + q2.pop();
	sum = sum + q2.pop();
	REQUIRE( sum == 18 );
	
}
