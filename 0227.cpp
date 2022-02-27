class Base2
{
public:
	virtual void f()
	{
		cout << "Base2::f" << endl;
	}
	virtual void g()
	{
		cout << "Base2::g" << endl;
	}
	virtual void h()
	{
		cout << "Base2::h" << endl;
	}
};
void main()
{ 
	D d;
	Base *pb = &d;
	pb->f();
	pb>h1();

	Base1 *pb1 = &d;
	pb1->f();

	Base2 *pb2 = &d;
	pb2->f();
}
