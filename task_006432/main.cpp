/*
  Допишіть код програми, щоб вона без помилок виводила повідомлення про те,
  що працівники продовжуть працювати навіть після того, як відділ де вони працювали раніше, розформовано.
  Підказка: Використовуйте std::vector для зберігання працівників у відділі.
 На додаткову оцінку можна реалізувати переведення працівника з одного відділа в інший.
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

    // інші методи допишіть самостійно
};

class Department
{
private:
    std::vector<Worker*> workers;

public:
    // Метод для додавання працівника до відділу
    void add(Worker* w)
    {
        workers.push_back(w);
    }
    ~Department() {
        disband();
    }

    // Метод для виведення інформації про працівників
    void display() const
    {
        for (const auto& worker : workers)
        {
            std::cout << worker->getName() << " працює в цьому відділі\n";
        }
    }

    // Метод для розформування відділу
    void disband()
    {
        std::cout << "Відділ розформовано!\n";
        
        workers.clear();
    }

    // Метод для переведення працівника в інший відділ
    void transfer(Worker* w, Department& newDepartment)
    {
        auto it = std::find(workers.begin(), workers.end(), w);
        if (it != workers.end())
        {
            // Знайдено працівника у поточному відділі
            workers.erase(it); // Видаляємо з поточного відділу
            newDepartment.add(w); // Додаємо до нового відділу
            std::cout << w->getName() << " переведено в інший відділ.\n";
        }
        else
        {
            std::cout << "Працівника " << w->getName() << " не знайдено у поточному відділі.\n";
        }
    }
};

int main() {
    system("chcp 1251>nul");



    Worker* w1 = new Worker("Антін");
    Worker* w2 = new Worker("Івасик");
    Worker* w3 = new Worker("Євген");
    Worker* w4 = new Worker("Їржик");

    {
        Department department;
        department.add(w1);
        department.add(w2);
        department.add(w3);

        std::cout << "Відділ до розформування:\n";
        department.display();

        department.disband();
    }

    std::cout << w1->getName() << " досі працює!\n";
    std::cout << w2->getName() << " досі працює!\n";
    std::cout << w3->getName() << " досі працює!\n";
    std::cout << w4->getName() << " досі працює!\n";

    Department department1;
    department1.add(w1);
    department1.add(w2);

    Department department2;
    department2.add(w3);

    std::cout << "Відділ 1 до переведення:\n";
    department1.display();
    std::cout << "Відділ 2 до переведення:\n";
    department2.display();

    // Переведемо працівника w2 з department1 в department2
    department1.transfer(w2, department2);

    std::cout << "Відділ 1 після переведення:\n";
    department1.display();
    std::cout << "Відділ 2 після переведення:\n";
    department2.display();

    delete w1;
    delete w2;
    delete w3;
    delete w4;

    return 0;
}
