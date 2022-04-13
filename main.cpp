#include<iostream>
#include <fstream>
#include<ctime>
using namespace std;
template <typename T>
struct STACK
{
private:
    T* stack; 
    int count; // Вершина стека - количество элементов типа T в стеке

public:
 
    STACK()
    {
        stack = nullptr; 
        count = 0; 
    }

 
    void push(T item)
    {
        T* tmp; 

      
      
            tmp = stack;

          
            stack = new T[count + 1];

           
            count++;

            
            for (int i = 0; i < count - 1; i++)
                stack[i] = tmp[i];

           
            stack[count - 1] = item;

           
            if (count > 1)
                delete[] tmp;
       
       
    }
  
    T pop()
    {
        if (count == 0)
            return 0;
        count--;
        return stack[count];
    }

   
    T Head()
    {
        if (count == 0)
            return 0;
        return stack[count - 1];
    }
    STACK operator=(const STACK& st)
    {
      
        if (count > 0)
        {
            count = 0;
            delete[] stack; 
        }             
            stack = new T[st.count];

           
            count = st.count;
            for (int i = 0; i < count; i++)
                stack[i] = st.stack[i];
      
       

     
        return *this;
    }
   
    STACK(const STACK& st)
    {
                 
            stack = new T[st.count];

          
            count = st.count;
            for (int i = 0; i < count; i++)
                stack[i] = st.stack[i];
       
    }

 

    ~STACK()
    {
        if (count > 0)
            delete[] stack;
    }

    void Print()
    {
        T* p; 

      
        p = stack;

       
        cout << "Stack: " << endl;
        if (count == 0)
            cout << "is empty." << endl;

        for (int i = 0; i < count; i++)
        {
            cout << "Item[" << i << "] = " << *p << endl;
            p++; 
        }
        cout << endl;
    }
    int Count()
    {
        return count;
    }
  
};
void task1()
{
    ofstream out("File.txt", ios::binary | ios::app);
    int num3 = 1; char c = '+';
    out << num3;
    out << num3;
    out << c;
    out.close();
    STACK <int>s;
	char sym;
    int num;
    int num1, num2;
	ifstream in("File.txt", ios::binary);
	while (!in.eof())
	{
		in >> sym;
		if (isdigit(sym))
		{
            num = sym - '0';
            s.push(num);
		}
        else
        {
            switch (sym)
            {
            case '-':
                num1 = s.pop();
                num2 = s.pop();
                num = num1 - num2;
                s.push(num);
                break;
            case '+':
                num1 = s.Head();
                s.pop();
                num2 = s.Head();
                s.pop();
                num = num1 + num2;
                s.push(num);
                break;
            case'*':
                num1 = s.pop();
                num2 = s.pop();
                num = num1 * num2;
                s.push(num);
                break;
            case'/':
                num1 = s.pop();
                num2 = s.pop();
                num = num1 / num2;
                s.push(num);
                break;
            default:
                cout<<"Некорректный символ\n";
            }
        }
	}

    s.Print();

}
int arrayUnique(int* ar, int size) 
{
    for (int counter1 = 0; counter1 < size; counter1++)
    {
        for (int counter2 = counter1 + 1; counter2 < size; counter2++)
        {
            if (ar[counter1] == ar[counter2]) 
            {
                for (int counter_shift = counter2; counter_shift < size - 1; counter_shift++)
                {
                   
                    ar[counter_shift] = ar[counter_shift + 1];
                }
                size -= 1; 

                if (ar[counter1] == ar[counter2]) 
                {
                    counter2--; 
                }
            }
        }
    }
    return size;
}
void task2()
{
  const int size = 5;
    int arr[size]{1,2,2,3,4};
    
   int size2 = arrayUnique(arr, size);
    int* arr_cor = new int[size2];
    int count = 0;
    for (int counter1 = 0; counter1 < arrayUnique(arr, size); counter1++)
    {
       arr_cor[count] = arr[counter1];
       count++;
    }
    for (int i = 0; i < size2; i++)
    {
        cout << arr_cor[i];
    }
}

int SumDigits(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
struct lFile
{
    void push_back(double data);
    void print();
    void new_list();
    int return_num();
    int find(int x);
private:

    int Size = 0;
    struct Node
    {
        lFile *l= new lFile;
        double data;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(double& data) { this->data = data; }
    };
    Node* head = nullptr;
    Node* tail = nullptr;

};
void lFile::push_back(double data) {
    Node* node = new Node(data);
    if (head == nullptr) {
        head = node;
        tail = node;
        head->prev = nullptr;
        tail->next = nullptr;
        this->Size++;
    }
    else {
        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail = node;
        node->data = data;
        this->Size++;
    }
}
void lFile::new_list()
{
    Node* iter = head;
    while (iter != nullptr)
    {
       
        iter->l->push_back(SumDigits(iter->data) % 10);
        iter = iter->next;
    }
}

int lFile::find(int x)
{
    Node* iter = head;
    while (iter != nullptr)
    {
        if (iter->l->head->data == x)
        {
            cout << "Число найдено" << endl;
            return 1;
        }
       
        iter = iter->next;
    }
    cout << "Число не найдено" << endl;
}
void lFile::print()
{

    Node* iter = head;
    while (iter != nullptr)
    {
        cout << iter->data << endl;

        iter = iter->next;
    }
}

void task3()
{
    lFile a;
    int num;
    srand(time(NULL));
    a.push_back(155);
    for (int i = 0; i < 5; i++)
    {
        num = rand() % 1000;
        a.push_back(num);
    }
    a.new_list();
    a.find(1);

}

int main()
{
	setlocale(LC_ALL, "rus");
  //task1();
    //task2();
    //task3();
	system("pause");
	return 0;
}