#include "pch.h"
#include "CppUnitTest.h"
#include "..\Program1\List.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{
	TEST_CLASS(LinkedListTest)
	{
	public:
		
		TEST_METHOD(ConstructorTest)
		{
			List lst;
			Assert::IsTrue (lst.GetSize() == 0);
		}
		TEST_METHOD(IsEmptyTest1)
		{
			List lst;
			Assert::IsTrue(lst.isEmpty());
		}
		TEST_METHOD(IsEmptyTest2)
		{
			List lst;
			lst.push_back(3);
			Assert::IsTrue(lst.isEmpty() == false);
		}
		TEST_METHOD(AtTest1)
		{
			List lst;
			lst.push_back(3);
			Assert::IsTrue(lst.at(0) == 3);
		}
		TEST_METHOD(AtTest2)
		{
			List lst;
			lst.push_back(3);
			lst.push_front(2);
			Assert::IsTrue(lst.at(0) == 2, L"Assert 1");
			Assert::IsTrue(lst.at(1) == 3, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 2, L"Assert 3");
		}
		TEST_METHOD(AtTest3)
		{
			List lst;
			lst.push_back(3);
			try
			{
				lst.at(-5);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect input.");
			}
		}
		TEST_METHOD(GetSizeTest1)
		{
			List lst;
			Assert::IsTrue(lst.GetSize() == 0);
		}
		TEST_METHOD(GetSizeTest2)
		{
			List lst;
			lst.push_back(3);
			lst.push_front(2);
			Assert::IsTrue(lst.GetSize() == 2);
		}
		TEST_METHOD(GetSizeTest3)
		{
			List lst;
			lst.push_back(3);
			lst.push_front(2);
			lst.pop_back();
			lst.pop_front();
			Assert::IsTrue(lst.GetSize() == 0);
		}

		TEST_METHOD(PushBackTest1)
		{
			List lst;
			lst.push_back(3);
			Assert::IsTrue(lst.GetSize() == 1, L"Assert 1");
			Assert::IsTrue(lst.at(0) == 3, L"Assert 2");
		}
		TEST_METHOD(PushBackTest2)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			Assert::IsTrue(lst.GetSize() == 4, L"Assert 1");
			Assert::IsTrue(lst.at(3) == 3, L"Assert 2");
		}
		TEST_METHOD(PushFrontTest1)
		{
			List lst;
			lst.push_front(3);
			Assert::IsTrue(lst.GetSize() == 1, L"Assert 1");
			Assert::IsTrue(lst.at(0) == 3, L"Assert 2");
		}
		TEST_METHOD(PushFrontTest2)
		{
			List lst;
			lst.push_front(0);
			lst.push_front(1);
			lst.push_front(2);
			lst.push_front(3);
			Assert::IsTrue(lst.GetSize() == 4, L"Assert 1");
			Assert::IsTrue(lst.at(3) == 0, L"Assert 2");
		}
		TEST_METHOD(PopBackTest1)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.pop_back();
			Assert::IsTrue(lst.GetSize() == 3);
		}
		TEST_METHOD(PopBackTest2)
		{
			List lst;
			lst.push_back(0);
			lst.pop_back();
			Assert::IsTrue(lst.GetSize() == 0);
		}
		TEST_METHOD(PopBackTest3)
		{
			List lst;
			try
			{
				lst.pop_back();
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Linked list is Empty.");
			}
		}
		TEST_METHOD(PopFrontTest1)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.pop_front();
			Assert::IsTrue(lst.at(0) == 1, L"Assert 1");
			Assert::IsTrue(lst.at(1) == 2, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 3, L"Assert 3");
		}
		TEST_METHOD(PopFrontTest2)
		{
			List lst;
			lst.push_back(0);
			lst.pop_front();
			Assert::IsTrue(lst.isEmpty(), L"Assert 1");
		}
		TEST_METHOD(PopFrontTest3)
		{
			List lst;
			try
			{
				lst.pop_front();
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Linked list is Empty.");
			}
		}
		TEST_METHOD(InsertTest1)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.insert(0, 21);
			Assert::IsTrue(lst.at(0) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(1) == 0, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 4, L"Assert 3");
		}
		TEST_METHOD(InsertTest2)
		{
			List lst;
			lst.insert(0, 21);
			Assert::IsTrue(lst.at(0) == 21, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 1, L"Assert 2");
		}
		TEST_METHOD(InsertTest3)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.insert(2, 21);
			Assert::IsTrue(lst.at(2) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(3) == 2, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 4, L"Assert 3");
		}
		TEST_METHOD(InsertTest4)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.insert(2, 21);
			Assert::IsTrue(lst.at(2) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(3) == 2, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 6, L"Assert 3");
		}
		TEST_METHOD(InsertTest5)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			try
			{
				lst.insert(-3, 21);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect input.");
			}
		}
		TEST_METHOD(SetTest1)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.set(0, 21);
			Assert::IsTrue(lst.at(0) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(1) == 1, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 3, L"Assert 3");
		}
		TEST_METHOD(SetTest2)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.push_back(6);
			lst.push_back(7);
			lst.push_back(8);
			lst.set(2, 21);
			Assert::IsTrue(lst.at(2) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(3) == 3, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 9, L"Assert 3");
		}
		TEST_METHOD(SetTest3)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.push_back(6);
			lst.push_back(7);
			lst.push_back(8);
			lst.set(7, 21);
			Assert::IsTrue(lst.at(7) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(8) == 8, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 9, L"Assert 3");
		}
		TEST_METHOD(SetTest4)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.push_back(6);
			lst.push_back(7);
			lst.push_back(8);
			lst.set(8, 21);
			Assert::IsTrue(lst.at(8) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(7) == 7, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 9, L"Assert 3");
		}
		TEST_METHOD(SetTest5)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			try
			{
				lst.set(-3, 21);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect input.");
			}
		}
		TEST_METHOD(PushBackListTest1)
		{
			List lst;
			lst.push_back(5);
			lst.push_back(6);
			List lst2;
			lst2.push_back(3);
			lst2.push_back(4);
			lst.push_front(lst2);
			Assert::IsTrue(lst.at(1) == 4, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 4, L"Assert 2");
		}
		TEST_METHOD(PushBackListTest2)
		{
			List lst;
			List lst2;
			lst2.push_back(0);
			lst2.push_back(1);
			lst.push_front(lst2);
			Assert::IsTrue(lst.at(0) == 0, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 2, L"Assert 2");
		}
		TEST_METHOD(PushBackListTest3)
		{
			List lst;
			lst.push_back(5);
			lst.push_back(6);
			List lst2;
			try
			{
				lst.push_front(lst2);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Inserting an empty list at the beginning is not possible.");
			}
		}
		TEST_METHOD(RemoveTest1)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.remove(0);
			Assert::IsTrue(lst.at(0) == 1, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 1, L"Assert 2");
		}
		TEST_METHOD(RemoveTest2)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.push_back(6);
			lst.push_back(7);
			lst.push_back(8);
			lst.remove(2);
			Assert::IsTrue(lst.at(2) == 3, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 8, L"Assert 2");
		}
		TEST_METHOD(RemoveTest3)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.push_back(6);
			lst.push_back(7);
			lst.push_back(8);
			lst.remove(6);
			Assert::IsTrue(lst.at(6) == 7, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 8, L"Assert 2");
		}
		TEST_METHOD(RemoveTest4)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.remove(5);
			Assert::IsTrue(lst.at(4) == 4, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 5, L"Assert 2");
		}
		TEST_METHOD(RemoveTest5)
		{
			List lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			try
			{
				lst.remove(-2);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect input.");
			}
		}
	};
}