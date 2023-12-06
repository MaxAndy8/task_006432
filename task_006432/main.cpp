/*
  �������� ��� ��������, ��� ���� ��� ������� �������� ����������� ��� ��,
  �� ���������� ���������� ��������� ����� ���� ����, �� ���� �� ���� ��������� �����, ������������.
  ϳ������: �������������� std::vector ��� ��������� ���������� � ����.
 �� ��������� ������ ����� ���������� ����������� ���������� � ������ ����� � �����.
*/
#include <iostream>
#include <vector>

class Worker
{
protected:
    std::string name;

public:
    Worker(std::string n) : name(n) {}

    std::string getName() const
    {
        return name;
    }

    // ���� ������ �������� ���������
};

class Department
{
private:
    std::vector<Worker*> workers;

public:
    // ����� ��� ��������� ���������� �� �����
    void add(Worker* w)
    {
        workers.push_back(w);
    }
    ~Department() {
        disband();
    }

    // ����� ��� ��������� ���������� ��� ����������
    void display() const
    {
        for (const auto& worker : workers)
        {
            std::cout << worker->getName() << " ������ � ����� ����\n";
        }
    }

    // ����� ��� ������������� �����
    void disband()
    {
        std::cout << "³��� ������������!\n";
        
        workers.clear();
    }

    // ����� ��� ����������� ���������� � ����� ����
    void transfer(Worker* w, Department& newDepartment)
    {
        auto it = std::find(workers.begin(), workers.end(), w);
        if (it != workers.end())
        {
            // �������� ���������� � ��������� ����
            workers.erase(it); // ��������� � ��������� �����
            newDepartment.add(w); // ������ �� ������ �����
            std::cout << w->getName() << " ���������� � ����� ����.\n";
        }
        else
        {
            std::cout << "���������� " << w->getName() << " �� �������� � ��������� ����.\n";
        }
    }
};

int main() {
    system("chcp 1251>nul");



    Worker* w1 = new Worker("����");
    Worker* w2 = new Worker("������");
    Worker* w3 = new Worker("�����");
    Worker* w4 = new Worker("�����");

    {
        Department department;
        department.add(w1);
        department.add(w2);
        department.add(w3);

        std::cout << "³��� �� �������������:\n";
        department.display();

        department.disband();
    }

    std::cout << w1->getName() << " ��� ������!\n";
    std::cout << w2->getName() << " ��� ������!\n";
    std::cout << w3->getName() << " ��� ������!\n";
    std::cout << w4->getName() << " ��� ������!\n";

    Department department1;
    department1.add(w1);
    department1.add(w2);

    Department department2;
    department2.add(w3);

    std::cout << "³��� 1 �� �����������:\n";
    department1.display();
    std::cout << "³��� 2 �� �����������:\n";
    department2.display();

    // ���������� ���������� w2 � department1 � department2
    department1.transfer(w2, department2);

    std::cout << "³��� 1 ���� �����������:\n";
    department1.display();
    std::cout << "³��� 2 ���� �����������:\n";
    department2.display();

    delete w1;
    delete w2;
    delete w3;
    delete w4;

    return 0;
}
