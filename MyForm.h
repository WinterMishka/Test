#pragma once
#include <random>

int a, click;

int generate_and_clear() {
	// Создаем статическую переменную, которая хранит последнее сгенерированное число
	static int last_number = 0;
	srand(time(NULL));
	// Если число не равно нулю, то очищаем его и возвращаем ноль
	if (last_number != 0) {
		last_number = 0;
		return 0;
	}
	// Иначе генерируем новое случайное число от 1 до 10 и сохраняем его в переменной
	else {
		last_number = rand() % 10 + 1;
		return last_number;
	}
}

void funk(System::Object^ sender, System::EventArgs^ e, RadioButton^ radioButton1, RadioButton^ radioButton2, RadioButton^ radioButton3, Label^ label1) {
	int a = generate_and_clear(); // Получаем случайное число
	int click = 0; // Объявляем переменную для подсчета очков
	// Получаем указатель на pictureBox, по которому кликнули
	PictureBox^ pictureBox = (PictureBox^)sender;
	// Проверяем, какой уровень сложности выбран
	if (radioButton1->Checked) { // Легкий уровень
		if (a == 1 || a == 2 || a == 3) { // Если число от 1 до 3
			click++; // Увеличиваем очки на 1
			pictureBox->Image = System::Drawing::Image::FromFile("1.jpg"); // Показываем картинку с 1
			label1->Text = ("Счёт: " + click)->ToString(); // Обновляем текст счета
			label1->Refresh(); // Обновляем метку
		}
		else if (a == 4 || a == 5 || a == 6) { // Если число от 4 до 6
			click = click + 2; // Увеличиваем очки на 2
			pictureBox->Image = System::Drawing::Image::FromFile("2.jpg"); // Показываем картинку с 2
			label1->Text = ("Счёт: " + click)->ToString(); // Обновляем текст счета
			label1->Refresh(); // Обновляем метку
		}
		else if (a == 7 || a == 8 || a == 9) { // Если число от 7 до 9
			click = click + 3; // Увеличиваем очки на 3
			pictureBox->Image = System::Drawing::Image::FromFile("3.jpg"); // Показываем картинку с 3
			label1->Text = ("Счёт: " + click)->ToString(); // Обновляем текст счета
			label1->Refresh(); // Обновляем метку
		}
		else if (a == 10) { // Если число равно 10
			pictureBox->Image = System::Drawing::Image::FromFile("krest.jpg"); // Показываем картинку с крестом
			MessageBox::Show("Вы проиграли", "Game Over", MessageBoxButtons::OK, MessageBoxIcon::Error); // Выводим сообщение о проигрыше
		}
	}
	else if (radioButton2->Checked) { // Нормальный уровень
		if (a == 1 || a == 2) { // Если число от 1 до 2
			click++; // Увеличиваем очки на 1
			pictureBox->Image = System::Drawing::Image::FromFile("1.jpg"); // Показываем картинку с 1
			label1->Text = ("Счёт: " + click)->ToString(); // Обновляем текст счета
			label1->Refresh(); // Обновляем метку
		}
		else if (a == 3 || a == 4) { // Если число от 3 до 4
			click = click + 2; // Увеличиваем очки на 2
			pictureBox->Image = System::Drawing::Image::FromFile("2.jpg"); // Показываем картинку с 2
			label1->Text = ("Счёт: " + click)->ToString(); // Обновляем текст счета
			label1->Refresh(); // Обновляем метку
		}
		else if (a == 5 || a == 6) { // Если число от 5 до 6
			click = click + 3; // Увеличиваем очки на 3
			pictureBox->Image = System::Drawing::Image::FromFile("3.jpg"); // Показываем картинку с 3
			label1->Text = ("Счёт: " + click)->ToString(); // Обновляем текст счета
			label1->Refresh(); // Обновляем метку
		}
		else if (a == 7 || a == 8 || a == 9 || a == 10) { // Если число от 7 до10 
			pictureBox->Image = System::Drawing::Image::FromFile("krest.jpg"); // Показываем картинку с крестом 
			MessageBox::Show("Вы проиграли", "Game Over", MessageBoxButtons::OK, MessageBoxIcon::Error); // Выводим сообщение о проигрыше 
		}
	}
	else if (radioButton3->Checked) { // Сложный уровень 
		if (a == 1) { // Если число равно 
			click++;
			pictureBox->Image = System::Drawing::Image::FromFile("1.jpg");
			label1->Text = ("Счёт: " + click)->ToString();
			label1->Refresh();
		}
		else if (a == 2) {
			click = click + 2;
			pictureBox->Image = System::Drawing::Image::FromFile("2.jpg");
			label1->Text = ("Счёт: " + click)->ToString();
			label1->Refresh();
		}
		else if (a == 3) {
			click = click + 3;
			pictureBox->Image = System::Drawing::Image::FromFile("3.jpg");
			label1->Text = ("Счёт: " + click)->ToString();
			label1->Refresh();
		}
		else if (a == 4 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9 || a == 10) {
			pictureBox->Image = System::Drawing::Image::FromFile("krest.jpg");
			MessageBox::Show("Вы проиграли", "Game Over", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

namespace test {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::PictureBox^ pictureBox11;
	private: System::Windows::Forms::PictureBox^ pictureBox12;
	private: System::Windows::Forms::PictureBox^ pictureBox13;
	private: System::Windows::Forms::PictureBox^ pictureBox14;
	private: System::Windows::Forms::PictureBox^ pictureBox15;
	private: System::Windows::Forms::PictureBox^ pictureBox16;
	private: System::Windows::Forms::PictureBox^ pictureBox17;
	private: System::Windows::Forms::PictureBox^ pictureBox18;
	private: System::Windows::Forms::PictureBox^ pictureBox19;
	private: System::Windows::Forms::PictureBox^ pictureBox20;
	private: System::Windows::Forms::PictureBox^ pictureBox21;
	private: System::Windows::Forms::PictureBox^ pictureBox22;
	private: System::Windows::Forms::PictureBox^ pictureBox23;
	private: System::Windows::Forms::PictureBox^ pictureBox24;
	private: System::Windows::Forms::PictureBox^ pictureBox25;
	private: System::Windows::Forms::PictureBox^ pictureBox26;
	private: System::Windows::Forms::PictureBox^ pictureBox27;
	private: System::Windows::Forms::PictureBox^ pictureBox28;
	private: System::Windows::Forms::PictureBox^ pictureBox29;
	private: System::Windows::Forms::PictureBox^ pictureBox30;
	private: System::Windows::Forms::PictureBox^ pictureBox31;
	private: System::Windows::Forms::PictureBox^ pictureBox32;
	private: System::Windows::Forms::PictureBox^ pictureBox33;
	private: System::Windows::Forms::PictureBox^ pictureBox34;
	private: System::Windows::Forms::PictureBox^ pictureBox35;
	private: System::Windows::Forms::PictureBox^ pictureBox36;
	private: System::Windows::Forms::PictureBox^ pictureBox37;
	private: System::Windows::Forms::PictureBox^ pictureBox38;
	private: System::Windows::Forms::PictureBox^ pictureBox39;
	private: System::Windows::Forms::PictureBox^ pictureBox40;
	private: System::Windows::Forms::PictureBox^ pictureBox41;
	private: System::Windows::Forms::PictureBox^ pictureBox42;
	private: System::Windows::Forms::PictureBox^ pictureBox43;
	private: System::Windows::Forms::PictureBox^ pictureBox44;
	private: System::Windows::Forms::PictureBox^ pictureBox45;
	private: System::Windows::Forms::PictureBox^ pictureBox46;
	private: System::Windows::Forms::PictureBox^ pictureBox47;
	private: System::Windows::Forms::PictureBox^ pictureBox48;
	private: System::Windows::Forms::PictureBox^ pictureBox49;
	private: System::Windows::Forms::PictureBox^ pictureBox50;
	private: System::Windows::Forms::PictureBox^ pictureBox51;
	private: System::Windows::Forms::PictureBox^ pictureBox52;
	private: System::Windows::Forms::PictureBox^ pictureBox53;
	private: System::Windows::Forms::PictureBox^ pictureBox54;
	private: System::Windows::Forms::PictureBox^ pictureBox55;
	private: System::Windows::Forms::PictureBox^ pictureBox56;
	private: System::Windows::Forms::PictureBox^ pictureBox57;
	private: System::Windows::Forms::PictureBox^ pictureBox58;
	private: System::Windows::Forms::PictureBox^ pictureBox59;
	private: System::Windows::Forms::PictureBox^ pictureBox60;
	private: System::Windows::Forms::PictureBox^ pictureBox61;
	private: System::Windows::Forms::PictureBox^ pictureBox62;
	private: System::Windows::Forms::PictureBox^ pictureBox63;
	private: System::Windows::Forms::PictureBox^ pictureBox64;
	private: System::Windows::Forms::PictureBox^ pictureBox65;
	private: System::Windows::Forms::PictureBox^ pictureBox66;
	private: System::Windows::Forms::PictureBox^ pictureBox67;
	private: System::Windows::Forms::PictureBox^ pictureBox68;
	private: System::Windows::Forms::PictureBox^ pictureBox69;
	private: System::Windows::Forms::PictureBox^ pictureBox70;
	private: System::Windows::Forms::PictureBox^ pictureBox71;
	private: System::Windows::Forms::PictureBox^ pictureBox72;
	private: System::Windows::Forms::PictureBox^ pictureBox73;
	private: System::Windows::Forms::PictureBox^ pictureBox74;
	private: System::Windows::Forms::PictureBox^ pictureBox75;
	private: System::Windows::Forms::PictureBox^ pictureBox76;
	private: System::Windows::Forms::PictureBox^ pictureBox77;
	private: System::Windows::Forms::PictureBox^ pictureBox78;
	private: System::Windows::Forms::PictureBox^ pictureBox79;
	private: System::Windows::Forms::PictureBox^ pictureBox80;
	private: System::Windows::Forms::PictureBox^ pictureBox81;
	public: System::Windows::Forms::RadioButton^ radioButton1;
	public: System::Windows::Forms::RadioButton^ radioButton2;
	public: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::Button^ button1;





	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox23 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox24 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox31 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox32 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox34 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox35 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox36 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox37 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox38 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox39 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox40 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox41 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox42 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox43 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox44 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox45 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox46 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox47 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox48 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox49 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox50 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox51 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox52 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox53 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox54 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox55 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox56 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox57 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox58 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox59 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox60 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox61 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox62 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox63 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox64 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox65 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox66 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox67 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox68 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox69 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox70 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox71 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox72 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox73 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox74 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox75 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox76 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox77 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox78 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox79 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox80 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox81 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox35))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox36))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox37))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox38))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox39))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox40))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox41))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox42))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox43))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox44))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox45))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox46))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox47))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox48))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox49))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox50))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox51))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox52))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox53))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox54))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox55))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox56))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox57))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox58))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox59))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox60))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox61))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox62))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox63))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox64))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox65))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox66))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox67))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox68))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox69))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox70))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox71))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox72))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox73))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox74))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox75))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox76))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox77))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox78))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox79))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox80))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox81))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(874, 48);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Кол-во";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox1->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.ErrorImage")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(47, 32);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(50, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox2->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.ErrorImage")));
			this->pictureBox2->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.InitialImage")));
			this->pictureBox2->Location = System::Drawing::Point(103, 32);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(50, 50);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox3->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.ErrorImage")));
			this->pictureBox3->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.InitialImage")));
			this->pictureBox3->Location = System::Drawing::Point(159, 32);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(50, 50);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &MyForm::pictureBox3_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox4->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.ErrorImage")));
			this->pictureBox4->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.InitialImage")));
			this->pictureBox4->Location = System::Drawing::Point(215, 33);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(50, 50);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &MyForm::pictureBox4_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox5->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.ErrorImage")));
			this->pictureBox5->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.InitialImage")));
			this->pictureBox5->Location = System::Drawing::Point(271, 33);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(50, 50);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 4;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &MyForm::pictureBox5_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox6->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.ErrorImage")));
			this->pictureBox6->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.InitialImage")));
			this->pictureBox6->Location = System::Drawing::Point(327, 32);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(50, 50);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 5;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &MyForm::pictureBox6_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox7->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.ErrorImage")));
			this->pictureBox7->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.InitialImage")));
			this->pictureBox7->Location = System::Drawing::Point(383, 32);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(50, 50);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox7->TabIndex = 6;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Click += gcnew System::EventHandler(this, &MyForm::pictureBox7_Click);
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox8->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.ErrorImage")));
			this->pictureBox8->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.InitialImage")));
			this->pictureBox8->Location = System::Drawing::Point(439, 32);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(50, 50);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox8->TabIndex = 7;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->Click += gcnew System::EventHandler(this, &MyForm::pictureBox8_Click);
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox9->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.ErrorImage")));
			this->pictureBox9->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.InitialImage")));
			this->pictureBox9->Location = System::Drawing::Point(495, 33);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(50, 50);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox9->TabIndex = 8;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Click += gcnew System::EventHandler(this, &MyForm::pictureBox9_Click);
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox10->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.ErrorImage")));
			this->pictureBox10->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.InitialImage")));
			this->pictureBox10->Location = System::Drawing::Point(47, 90);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(50, 50);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox10->TabIndex = 10;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox11->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.ErrorImage")));
			this->pictureBox11->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.InitialImage")));
			this->pictureBox11->Location = System::Drawing::Point(103, 90);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(50, 50);
			this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox11->TabIndex = 11;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox12->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.ErrorImage")));
			this->pictureBox12->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.InitialImage")));
			this->pictureBox12->Location = System::Drawing::Point(159, 90);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(50, 50);
			this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox12->TabIndex = 12;
			this->pictureBox12->TabStop = false;
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox13->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.ErrorImage")));
			this->pictureBox13->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.InitialImage")));
			this->pictureBox13->Location = System::Drawing::Point(215, 90);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(50, 50);
			this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox13->TabIndex = 13;
			this->pictureBox13->TabStop = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox14->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox14.ErrorImage")));
			this->pictureBox14->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox14.InitialImage")));
			this->pictureBox14->Location = System::Drawing::Point(271, 89);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(50, 50);
			this->pictureBox14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox14->TabIndex = 14;
			this->pictureBox14->TabStop = false;
			// 
			// pictureBox15
			// 
			this->pictureBox15->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox15->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox15.ErrorImage")));
			this->pictureBox15->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox15.InitialImage")));
			this->pictureBox15->Location = System::Drawing::Point(327, 88);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(50, 50);
			this->pictureBox15->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox15->TabIndex = 15;
			this->pictureBox15->TabStop = false;
			// 
			// pictureBox16
			// 
			this->pictureBox16->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox16->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox16.ErrorImage")));
			this->pictureBox16->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox16.InitialImage")));
			this->pictureBox16->Location = System::Drawing::Point(383, 88);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(50, 50);
			this->pictureBox16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox16->TabIndex = 16;
			this->pictureBox16->TabStop = false;
			// 
			// pictureBox17
			// 
			this->pictureBox17->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox17->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox17.ErrorImage")));
			this->pictureBox17->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox17.InitialImage")));
			this->pictureBox17->Location = System::Drawing::Point(439, 88);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(50, 50);
			this->pictureBox17->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox17->TabIndex = 17;
			this->pictureBox17->TabStop = false;
			// 
			// pictureBox18
			// 
			this->pictureBox18->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox18->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox18.ErrorImage")));
			this->pictureBox18->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox18.InitialImage")));
			this->pictureBox18->Location = System::Drawing::Point(495, 90);
			this->pictureBox18->Name = L"pictureBox18";
			this->pictureBox18->Size = System::Drawing::Size(50, 50);
			this->pictureBox18->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox18->TabIndex = 18;
			this->pictureBox18->TabStop = false;
			// 
			// pictureBox19
			// 
			this->pictureBox19->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox19->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox19.ErrorImage")));
			this->pictureBox19->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox19.InitialImage")));
			this->pictureBox19->Location = System::Drawing::Point(47, 146);
			this->pictureBox19->Name = L"pictureBox19";
			this->pictureBox19->Size = System::Drawing::Size(50, 50);
			this->pictureBox19->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox19->TabIndex = 19;
			this->pictureBox19->TabStop = false;
			// 
			// pictureBox20
			// 
			this->pictureBox20->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox20->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox20.ErrorImage")));
			this->pictureBox20->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox20.InitialImage")));
			this->pictureBox20->Location = System::Drawing::Point(103, 146);
			this->pictureBox20->Name = L"pictureBox20";
			this->pictureBox20->Size = System::Drawing::Size(50, 50);
			this->pictureBox20->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox20->TabIndex = 20;
			this->pictureBox20->TabStop = false;
			// 
			// pictureBox21
			// 
			this->pictureBox21->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox21->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox21.ErrorImage")));
			this->pictureBox21->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox21.InitialImage")));
			this->pictureBox21->Location = System::Drawing::Point(159, 146);
			this->pictureBox21->Name = L"pictureBox21";
			this->pictureBox21->Size = System::Drawing::Size(50, 50);
			this->pictureBox21->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox21->TabIndex = 21;
			this->pictureBox21->TabStop = false;
			// 
			// pictureBox22
			// 
			this->pictureBox22->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox22->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox22.ErrorImage")));
			this->pictureBox22->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox22.InitialImage")));
			this->pictureBox22->Location = System::Drawing::Point(215, 146);
			this->pictureBox22->Name = L"pictureBox22";
			this->pictureBox22->Size = System::Drawing::Size(50, 50);
			this->pictureBox22->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox22->TabIndex = 22;
			this->pictureBox22->TabStop = false;
			// 
			// pictureBox23
			// 
			this->pictureBox23->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox23->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox23.ErrorImage")));
			this->pictureBox23->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox23.InitialImage")));
			this->pictureBox23->Location = System::Drawing::Point(271, 146);
			this->pictureBox23->Name = L"pictureBox23";
			this->pictureBox23->Size = System::Drawing::Size(50, 50);
			this->pictureBox23->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox23->TabIndex = 23;
			this->pictureBox23->TabStop = false;
			// 
			// pictureBox24
			// 
			this->pictureBox24->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox24->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox24.ErrorImage")));
			this->pictureBox24->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox24.InitialImage")));
			this->pictureBox24->Location = System::Drawing::Point(327, 144);
			this->pictureBox24->Name = L"pictureBox24";
			this->pictureBox24->Size = System::Drawing::Size(50, 50);
			this->pictureBox24->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox24->TabIndex = 24;
			this->pictureBox24->TabStop = false;
			// 
			// pictureBox25
			// 
			this->pictureBox25->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox25->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox25.ErrorImage")));
			this->pictureBox25->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox25.InitialImage")));
			this->pictureBox25->Location = System::Drawing::Point(383, 143);
			this->pictureBox25->Name = L"pictureBox25";
			this->pictureBox25->Size = System::Drawing::Size(50, 50);
			this->pictureBox25->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox25->TabIndex = 25;
			this->pictureBox25->TabStop = false;
			// 
			// pictureBox26
			// 
			this->pictureBox26->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox26->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox26.ErrorImage")));
			this->pictureBox26->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox26.InitialImage")));
			this->pictureBox26->Location = System::Drawing::Point(439, 144);
			this->pictureBox26->Name = L"pictureBox26";
			this->pictureBox26->Size = System::Drawing::Size(50, 50);
			this->pictureBox26->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox26->TabIndex = 26;
			this->pictureBox26->TabStop = false;
			// 
			// pictureBox27
			// 
			this->pictureBox27->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox27->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox27.ErrorImage")));
			this->pictureBox27->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox27.InitialImage")));
			this->pictureBox27->Location = System::Drawing::Point(495, 144);
			this->pictureBox27->Name = L"pictureBox27";
			this->pictureBox27->Size = System::Drawing::Size(50, 50);
			this->pictureBox27->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox27->TabIndex = 27;
			this->pictureBox27->TabStop = false;
			// 
			// pictureBox28
			// 
			this->pictureBox28->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox28->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox28.ErrorImage")));
			this->pictureBox28->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox28.InitialImage")));
			this->pictureBox28->Location = System::Drawing::Point(47, 202);
			this->pictureBox28->Name = L"pictureBox28";
			this->pictureBox28->Size = System::Drawing::Size(50, 50);
			this->pictureBox28->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox28->TabIndex = 28;
			this->pictureBox28->TabStop = false;
			// 
			// pictureBox29
			// 
			this->pictureBox29->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox29->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox29.ErrorImage")));
			this->pictureBox29->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox29.InitialImage")));
			this->pictureBox29->Location = System::Drawing::Point(103, 202);
			this->pictureBox29->Name = L"pictureBox29";
			this->pictureBox29->Size = System::Drawing::Size(50, 50);
			this->pictureBox29->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox29->TabIndex = 29;
			this->pictureBox29->TabStop = false;
			// 
			// pictureBox30
			// 
			this->pictureBox30->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox30->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox30.ErrorImage")));
			this->pictureBox30->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox30.InitialImage")));
			this->pictureBox30->Location = System::Drawing::Point(159, 202);
			this->pictureBox30->Name = L"pictureBox30";
			this->pictureBox30->Size = System::Drawing::Size(50, 50);
			this->pictureBox30->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox30->TabIndex = 30;
			this->pictureBox30->TabStop = false;
			this->pictureBox30->Click += gcnew System::EventHandler(this, &MyForm::pictureBox30_Click);
			// 
			// pictureBox31
			// 
			this->pictureBox31->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox31->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox31.ErrorImage")));
			this->pictureBox31->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox31.InitialImage")));
			this->pictureBox31->Location = System::Drawing::Point(215, 202);
			this->pictureBox31->Name = L"pictureBox31";
			this->pictureBox31->Size = System::Drawing::Size(50, 50);
			this->pictureBox31->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox31->TabIndex = 31;
			this->pictureBox31->TabStop = false;
			this->pictureBox31->Click += gcnew System::EventHandler(this, &MyForm::pictureBox31_Click);
			// 
			// pictureBox32
			// 
			this->pictureBox32->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox32->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox32.ErrorImage")));
			this->pictureBox32->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox32.InitialImage")));
			this->pictureBox32->Location = System::Drawing::Point(271, 202);
			this->pictureBox32->Name = L"pictureBox32";
			this->pictureBox32->Size = System::Drawing::Size(50, 50);
			this->pictureBox32->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox32->TabIndex = 32;
			this->pictureBox32->TabStop = false;
			this->pictureBox32->Click += gcnew System::EventHandler(this, &MyForm::pictureBox32_Click);
			// 
			// pictureBox33
			// 
			this->pictureBox33->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox33->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox33.ErrorImage")));
			this->pictureBox33->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox33.InitialImage")));
			this->pictureBox33->Location = System::Drawing::Point(327, 202);
			this->pictureBox33->Name = L"pictureBox33";
			this->pictureBox33->Size = System::Drawing::Size(50, 50);
			this->pictureBox33->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox33->TabIndex = 33;
			this->pictureBox33->TabStop = false;
			this->pictureBox33->Click += gcnew System::EventHandler(this, &MyForm::pictureBox33_Click);
			// 
			// pictureBox34
			// 
			this->pictureBox34->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox34->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox34.ErrorImage")));
			this->pictureBox34->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox34.InitialImage")));
			this->pictureBox34->Location = System::Drawing::Point(383, 202);
			this->pictureBox34->Name = L"pictureBox34";
			this->pictureBox34->Size = System::Drawing::Size(50, 50);
			this->pictureBox34->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox34->TabIndex = 34;
			this->pictureBox34->TabStop = false;
			this->pictureBox34->Click += gcnew System::EventHandler(this, &MyForm::pictureBox34_Click);
			// 
			// pictureBox35
			// 
			this->pictureBox35->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox35->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox35.ErrorImage")));
			this->pictureBox35->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox35.InitialImage")));
			this->pictureBox35->Location = System::Drawing::Point(439, 202);
			this->pictureBox35->Name = L"pictureBox35";
			this->pictureBox35->Size = System::Drawing::Size(50, 50);
			this->pictureBox35->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox35->TabIndex = 35;
			this->pictureBox35->TabStop = false;
			this->pictureBox35->Click += gcnew System::EventHandler(this, &MyForm::pictureBox35_Click);
			// 
			// pictureBox36
			// 
			this->pictureBox36->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox36->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox36.ErrorImage")));
			this->pictureBox36->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox36.InitialImage")));
			this->pictureBox36->Location = System::Drawing::Point(495, 202);
			this->pictureBox36->Name = L"pictureBox36";
			this->pictureBox36->Size = System::Drawing::Size(50, 50);
			this->pictureBox36->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox36->TabIndex = 36;
			this->pictureBox36->TabStop = false;
			this->pictureBox36->Click += gcnew System::EventHandler(this, &MyForm::pictureBox36_Click);
			// 
			// pictureBox37
			// 
			this->pictureBox37->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox37->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox37.ErrorImage")));
			this->pictureBox37->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox37.InitialImage")));
			this->pictureBox37->Location = System::Drawing::Point(47, 258);
			this->pictureBox37->Name = L"pictureBox37";
			this->pictureBox37->Size = System::Drawing::Size(50, 50);
			this->pictureBox37->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox37->TabIndex = 37;
			this->pictureBox37->TabStop = false;
			this->pictureBox37->Click += gcnew System::EventHandler(this, &MyForm::pictureBox37_Click);
			// 
			// pictureBox38
			// 
			this->pictureBox38->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox38->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox38.ErrorImage")));
			this->pictureBox38->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox38.InitialImage")));
			this->pictureBox38->Location = System::Drawing::Point(103, 258);
			this->pictureBox38->Name = L"pictureBox38";
			this->pictureBox38->Size = System::Drawing::Size(50, 50);
			this->pictureBox38->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox38->TabIndex = 38;
			this->pictureBox38->TabStop = false;
			this->pictureBox38->Click += gcnew System::EventHandler(this, &MyForm::pictureBox38_Click);
			// 
			// pictureBox39
			// 
			this->pictureBox39->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox39->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox39.ErrorImage")));
			this->pictureBox39->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox39.InitialImage")));
			this->pictureBox39->Location = System::Drawing::Point(159, 258);
			this->pictureBox39->Name = L"pictureBox39";
			this->pictureBox39->Size = System::Drawing::Size(50, 50);
			this->pictureBox39->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox39->TabIndex = 39;
			this->pictureBox39->TabStop = false;
			this->pictureBox39->Click += gcnew System::EventHandler(this, &MyForm::pictureBox39_Click);
			// 
			// pictureBox40
			// 
			this->pictureBox40->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox40->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox40.ErrorImage")));
			this->pictureBox40->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox40.InitialImage")));
			this->pictureBox40->Location = System::Drawing::Point(215, 258);
			this->pictureBox40->Name = L"pictureBox40";
			this->pictureBox40->Size = System::Drawing::Size(50, 50);
			this->pictureBox40->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox40->TabIndex = 40;
			this->pictureBox40->TabStop = false;
			this->pictureBox40->Click += gcnew System::EventHandler(this, &MyForm::pictureBox40_Click);
			// 
			// pictureBox41
			// 
			this->pictureBox41->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox41->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox41.ErrorImage")));
			this->pictureBox41->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox41.InitialImage")));
			this->pictureBox41->Location = System::Drawing::Point(271, 258);
			this->pictureBox41->Name = L"pictureBox41";
			this->pictureBox41->Size = System::Drawing::Size(50, 50);
			this->pictureBox41->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox41->TabIndex = 41;
			this->pictureBox41->TabStop = false;
			this->pictureBox41->Click += gcnew System::EventHandler(this, &MyForm::pictureBox41_Click);
			// 
			// pictureBox42
			// 
			this->pictureBox42->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox42->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox42.ErrorImage")));
			this->pictureBox42->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox42.InitialImage")));
			this->pictureBox42->Location = System::Drawing::Point(327, 258);
			this->pictureBox42->Name = L"pictureBox42";
			this->pictureBox42->Size = System::Drawing::Size(50, 50);
			this->pictureBox42->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox42->TabIndex = 42;
			this->pictureBox42->TabStop = false;
			this->pictureBox42->Click += gcnew System::EventHandler(this, &MyForm::pictureBox42_Click);
			// 
			// pictureBox43
			// 
			this->pictureBox43->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox43->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox43.ErrorImage")));
			this->pictureBox43->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox43.InitialImage")));
			this->pictureBox43->Location = System::Drawing::Point(383, 258);
			this->pictureBox43->Name = L"pictureBox43";
			this->pictureBox43->Size = System::Drawing::Size(50, 50);
			this->pictureBox43->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox43->TabIndex = 43;
			this->pictureBox43->TabStop = false;
			this->pictureBox43->Click += gcnew System::EventHandler(this, &MyForm::pictureBox43_Click);
			// 
			// pictureBox44
			// 
			this->pictureBox44->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox44->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox44.ErrorImage")));
			this->pictureBox44->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox44.InitialImage")));
			this->pictureBox44->Location = System::Drawing::Point(439, 258);
			this->pictureBox44->Name = L"pictureBox44";
			this->pictureBox44->Size = System::Drawing::Size(50, 50);
			this->pictureBox44->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox44->TabIndex = 44;
			this->pictureBox44->TabStop = false;
			this->pictureBox44->Click += gcnew System::EventHandler(this, &MyForm::pictureBox44_Click);
			// 
			// pictureBox45
			// 
			this->pictureBox45->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox45->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox45.ErrorImage")));
			this->pictureBox45->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox45.InitialImage")));
			this->pictureBox45->Location = System::Drawing::Point(495, 258);
			this->pictureBox45->Name = L"pictureBox45";
			this->pictureBox45->Size = System::Drawing::Size(50, 50);
			this->pictureBox45->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox45->TabIndex = 45;
			this->pictureBox45->TabStop = false;
			this->pictureBox45->Click += gcnew System::EventHandler(this, &MyForm::pictureBox45_Click);
			// 
			// pictureBox46
			// 
			this->pictureBox46->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox46->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox46.ErrorImage")));
			this->pictureBox46->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox46.InitialImage")));
			this->pictureBox46->Location = System::Drawing::Point(47, 314);
			this->pictureBox46->Name = L"pictureBox46";
			this->pictureBox46->Size = System::Drawing::Size(50, 50);
			this->pictureBox46->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox46->TabIndex = 46;
			this->pictureBox46->TabStop = false;
			this->pictureBox46->Click += gcnew System::EventHandler(this, &MyForm::pictureBox46_Click);
			// 
			// pictureBox47
			// 
			this->pictureBox47->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox47->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox47.ErrorImage")));
			this->pictureBox47->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox47.InitialImage")));
			this->pictureBox47->Location = System::Drawing::Point(103, 314);
			this->pictureBox47->Name = L"pictureBox47";
			this->pictureBox47->Size = System::Drawing::Size(50, 50);
			this->pictureBox47->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox47->TabIndex = 47;
			this->pictureBox47->TabStop = false;
			this->pictureBox47->Click += gcnew System::EventHandler(this, &MyForm::pictureBox47_Click);
			// 
			// pictureBox48
			// 
			this->pictureBox48->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox48->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox48.ErrorImage")));
			this->pictureBox48->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox48.InitialImage")));
			this->pictureBox48->Location = System::Drawing::Point(159, 314);
			this->pictureBox48->Name = L"pictureBox48";
			this->pictureBox48->Size = System::Drawing::Size(50, 50);
			this->pictureBox48->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox48->TabIndex = 48;
			this->pictureBox48->TabStop = false;
			this->pictureBox48->Click += gcnew System::EventHandler(this, &MyForm::pictureBox48_Click);
			// 
			// pictureBox49
			// 
			this->pictureBox49->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox49->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox49.ErrorImage")));
			this->pictureBox49->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox49.InitialImage")));
			this->pictureBox49->Location = System::Drawing::Point(215, 314);
			this->pictureBox49->Name = L"pictureBox49";
			this->pictureBox49->Size = System::Drawing::Size(50, 50);
			this->pictureBox49->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox49->TabIndex = 49;
			this->pictureBox49->TabStop = false;
			this->pictureBox49->Click += gcnew System::EventHandler(this, &MyForm::pictureBox49_Click);
			// 
			// pictureBox50
			// 
			this->pictureBox50->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox50->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox50.ErrorImage")));
			this->pictureBox50->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox50.InitialImage")));
			this->pictureBox50->Location = System::Drawing::Point(271, 314);
			this->pictureBox50->Name = L"pictureBox50";
			this->pictureBox50->Size = System::Drawing::Size(50, 50);
			this->pictureBox50->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox50->TabIndex = 50;
			this->pictureBox50->TabStop = false;
			this->pictureBox50->Click += gcnew System::EventHandler(this, &MyForm::pictureBox50_Click);
			// 
			// pictureBox51
			// 
			this->pictureBox51->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox51->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox51.ErrorImage")));
			this->pictureBox51->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox51.InitialImage")));
			this->pictureBox51->Location = System::Drawing::Point(327, 314);
			this->pictureBox51->Name = L"pictureBox51";
			this->pictureBox51->Size = System::Drawing::Size(50, 50);
			this->pictureBox51->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox51->TabIndex = 51;
			this->pictureBox51->TabStop = false;
			this->pictureBox51->Click += gcnew System::EventHandler(this, &MyForm::pictureBox51_Click);
			// 
			// pictureBox52
			// 
			this->pictureBox52->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox52->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox52.ErrorImage")));
			this->pictureBox52->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox52.InitialImage")));
			this->pictureBox52->Location = System::Drawing::Point(383, 314);
			this->pictureBox52->Name = L"pictureBox52";
			this->pictureBox52->Size = System::Drawing::Size(50, 50);
			this->pictureBox52->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox52->TabIndex = 52;
			this->pictureBox52->TabStop = false;
			this->pictureBox52->Click += gcnew System::EventHandler(this, &MyForm::pictureBox52_Click);
			// 
			// pictureBox53
			// 
			this->pictureBox53->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox53->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox53.ErrorImage")));
			this->pictureBox53->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox53.InitialImage")));
			this->pictureBox53->Location = System::Drawing::Point(439, 314);
			this->pictureBox53->Name = L"pictureBox53";
			this->pictureBox53->Size = System::Drawing::Size(50, 50);
			this->pictureBox53->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox53->TabIndex = 53;
			this->pictureBox53->TabStop = false;
			this->pictureBox53->Click += gcnew System::EventHandler(this, &MyForm::pictureBox53_Click);
			// 
			// pictureBox54
			// 
			this->pictureBox54->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox54->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox54.ErrorImage")));
			this->pictureBox54->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox54.InitialImage")));
			this->pictureBox54->Location = System::Drawing::Point(495, 314);
			this->pictureBox54->Name = L"pictureBox54";
			this->pictureBox54->Size = System::Drawing::Size(50, 50);
			this->pictureBox54->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox54->TabIndex = 54;
			this->pictureBox54->TabStop = false;
			this->pictureBox54->Click += gcnew System::EventHandler(this, &MyForm::pictureBox54_Click);
			// 
			// pictureBox55
			// 
			this->pictureBox55->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox55->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox55.ErrorImage")));
			this->pictureBox55->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox55.InitialImage")));
			this->pictureBox55->Location = System::Drawing::Point(47, 370);
			this->pictureBox55->Name = L"pictureBox55";
			this->pictureBox55->Size = System::Drawing::Size(50, 50);
			this->pictureBox55->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox55->TabIndex = 55;
			this->pictureBox55->TabStop = false;
			this->pictureBox55->Click += gcnew System::EventHandler(this, &MyForm::pictureBox55_Click);
			// 
			// pictureBox56
			// 
			this->pictureBox56->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox56->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox56.ErrorImage")));
			this->pictureBox56->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox56.InitialImage")));
			this->pictureBox56->Location = System::Drawing::Point(103, 370);
			this->pictureBox56->Name = L"pictureBox56";
			this->pictureBox56->Size = System::Drawing::Size(50, 50);
			this->pictureBox56->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox56->TabIndex = 56;
			this->pictureBox56->TabStop = false;
			this->pictureBox56->Click += gcnew System::EventHandler(this, &MyForm::pictureBox56_Click);
			// 
			// pictureBox57
			// 
			this->pictureBox57->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox57->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox57.ErrorImage")));
			this->pictureBox57->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox57.InitialImage")));
			this->pictureBox57->Location = System::Drawing::Point(159, 370);
			this->pictureBox57->Name = L"pictureBox57";
			this->pictureBox57->Size = System::Drawing::Size(50, 50);
			this->pictureBox57->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox57->TabIndex = 57;
			this->pictureBox57->TabStop = false;
			this->pictureBox57->Click += gcnew System::EventHandler(this, &MyForm::pictureBox57_Click);
			// 
			// pictureBox58
			// 
			this->pictureBox58->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox58->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox58.ErrorImage")));
			this->pictureBox58->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox58.InitialImage")));
			this->pictureBox58->Location = System::Drawing::Point(215, 370);
			this->pictureBox58->Name = L"pictureBox58";
			this->pictureBox58->Size = System::Drawing::Size(50, 50);
			this->pictureBox58->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox58->TabIndex = 58;
			this->pictureBox58->TabStop = false;
			this->pictureBox58->Click += gcnew System::EventHandler(this, &MyForm::pictureBox58_Click);
			// 
			// pictureBox59
			// 
			this->pictureBox59->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox59->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox59.ErrorImage")));
			this->pictureBox59->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox59.InitialImage")));
			this->pictureBox59->Location = System::Drawing::Point(271, 370);
			this->pictureBox59->Name = L"pictureBox59";
			this->pictureBox59->Size = System::Drawing::Size(50, 50);
			this->pictureBox59->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox59->TabIndex = 59;
			this->pictureBox59->TabStop = false;
			this->pictureBox59->Click += gcnew System::EventHandler(this, &MyForm::pictureBox59_Click);
			// 
			// pictureBox60
			// 
			this->pictureBox60->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox60->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox60.ErrorImage")));
			this->pictureBox60->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox60.InitialImage")));
			this->pictureBox60->Location = System::Drawing::Point(327, 370);
			this->pictureBox60->Name = L"pictureBox60";
			this->pictureBox60->Size = System::Drawing::Size(50, 50);
			this->pictureBox60->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox60->TabIndex = 60;
			this->pictureBox60->TabStop = false;
			this->pictureBox60->Click += gcnew System::EventHandler(this, &MyForm::pictureBox60_Click);
			// 
			// pictureBox61
			// 
			this->pictureBox61->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox61->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox61.ErrorImage")));
			this->pictureBox61->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox61.InitialImage")));
			this->pictureBox61->Location = System::Drawing::Point(383, 370);
			this->pictureBox61->Name = L"pictureBox61";
			this->pictureBox61->Size = System::Drawing::Size(50, 50);
			this->pictureBox61->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox61->TabIndex = 61;
			this->pictureBox61->TabStop = false;
			this->pictureBox61->Click += gcnew System::EventHandler(this, &MyForm::pictureBox61_Click);
			// 
			// pictureBox62
			// 
			this->pictureBox62->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox62->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox62.ErrorImage")));
			this->pictureBox62->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox62.InitialImage")));
			this->pictureBox62->Location = System::Drawing::Point(439, 370);
			this->pictureBox62->Name = L"pictureBox62";
			this->pictureBox62->Size = System::Drawing::Size(50, 50);
			this->pictureBox62->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox62->TabIndex = 62;
			this->pictureBox62->TabStop = false;
			this->pictureBox62->Click += gcnew System::EventHandler(this, &MyForm::pictureBox62_Click);
			// 
			// pictureBox63
			// 
			this->pictureBox63->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox63->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox63.ErrorImage")));
			this->pictureBox63->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox63.InitialImage")));
			this->pictureBox63->Location = System::Drawing::Point(495, 370);
			this->pictureBox63->Name = L"pictureBox63";
			this->pictureBox63->Size = System::Drawing::Size(50, 50);
			this->pictureBox63->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox63->TabIndex = 63;
			this->pictureBox63->TabStop = false;
			this->pictureBox63->Click += gcnew System::EventHandler(this, &MyForm::pictureBox63_Click);
			// 
			// pictureBox64
			// 
			this->pictureBox64->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox64->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox64.ErrorImage")));
			this->pictureBox64->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox64.InitialImage")));
			this->pictureBox64->Location = System::Drawing::Point(47, 426);
			this->pictureBox64->Name = L"pictureBox64";
			this->pictureBox64->Size = System::Drawing::Size(50, 50);
			this->pictureBox64->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox64->TabIndex = 64;
			this->pictureBox64->TabStop = false;
			this->pictureBox64->Click += gcnew System::EventHandler(this, &MyForm::pictureBox64_Click);
			// 
			// pictureBox65
			// 
			this->pictureBox65->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox65->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox65.ErrorImage")));
			this->pictureBox65->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox65.InitialImage")));
			this->pictureBox65->Location = System::Drawing::Point(103, 426);
			this->pictureBox65->Name = L"pictureBox65";
			this->pictureBox65->Size = System::Drawing::Size(50, 50);
			this->pictureBox65->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox65->TabIndex = 65;
			this->pictureBox65->TabStop = false;
			this->pictureBox65->Click += gcnew System::EventHandler(this, &MyForm::pictureBox65_Click);
			// 
			// pictureBox66
			// 
			this->pictureBox66->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox66->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox66.ErrorImage")));
			this->pictureBox66->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox66.InitialImage")));
			this->pictureBox66->Location = System::Drawing::Point(159, 426);
			this->pictureBox66->Name = L"pictureBox66";
			this->pictureBox66->Size = System::Drawing::Size(50, 50);
			this->pictureBox66->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox66->TabIndex = 66;
			this->pictureBox66->TabStop = false;
			this->pictureBox66->Click += gcnew System::EventHandler(this, &MyForm::pictureBox66_Click);
			// 
			// pictureBox67
			// 
			this->pictureBox67->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox67->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox67.ErrorImage")));
			this->pictureBox67->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox67.InitialImage")));
			this->pictureBox67->Location = System::Drawing::Point(215, 426);
			this->pictureBox67->Name = L"pictureBox67";
			this->pictureBox67->Size = System::Drawing::Size(50, 50);
			this->pictureBox67->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox67->TabIndex = 67;
			this->pictureBox67->TabStop = false;
			this->pictureBox67->Click += gcnew System::EventHandler(this, &MyForm::pictureBox67_Click);
			// 
			// pictureBox68
			// 
			this->pictureBox68->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox68->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox68.ErrorImage")));
			this->pictureBox68->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox68.InitialImage")));
			this->pictureBox68->Location = System::Drawing::Point(271, 426);
			this->pictureBox68->Name = L"pictureBox68";
			this->pictureBox68->Size = System::Drawing::Size(50, 50);
			this->pictureBox68->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox68->TabIndex = 68;
			this->pictureBox68->TabStop = false;
			this->pictureBox68->Click += gcnew System::EventHandler(this, &MyForm::pictureBox68_Click);
			// 
			// pictureBox69
			// 
			this->pictureBox69->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox69->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox69.ErrorImage")));
			this->pictureBox69->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox69.InitialImage")));
			this->pictureBox69->Location = System::Drawing::Point(327, 426);
			this->pictureBox69->Name = L"pictureBox69";
			this->pictureBox69->Size = System::Drawing::Size(50, 50);
			this->pictureBox69->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox69->TabIndex = 69;
			this->pictureBox69->TabStop = false;
			this->pictureBox69->Click += gcnew System::EventHandler(this, &MyForm::pictureBox69_Click);
			// 
			// pictureBox70
			// 
			this->pictureBox70->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox70->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox70.ErrorImage")));
			this->pictureBox70->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox70.InitialImage")));
			this->pictureBox70->Location = System::Drawing::Point(383, 426);
			this->pictureBox70->Name = L"pictureBox70";
			this->pictureBox70->Size = System::Drawing::Size(50, 50);
			this->pictureBox70->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox70->TabIndex = 70;
			this->pictureBox70->TabStop = false;
			this->pictureBox70->Click += gcnew System::EventHandler(this, &MyForm::pictureBox70_Click);
			// 
			// pictureBox71
			// 
			this->pictureBox71->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox71->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox71.ErrorImage")));
			this->pictureBox71->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox71.InitialImage")));
			this->pictureBox71->Location = System::Drawing::Point(439, 426);
			this->pictureBox71->Name = L"pictureBox71";
			this->pictureBox71->Size = System::Drawing::Size(50, 50);
			this->pictureBox71->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox71->TabIndex = 71;
			this->pictureBox71->TabStop = false;
			this->pictureBox71->Click += gcnew System::EventHandler(this, &MyForm::pictureBox71_Click);
			// 
			// pictureBox72
			// 
			this->pictureBox72->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox72->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox72.ErrorImage")));
			this->pictureBox72->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox72.InitialImage")));
			this->pictureBox72->Location = System::Drawing::Point(495, 426);
			this->pictureBox72->Name = L"pictureBox72";
			this->pictureBox72->Size = System::Drawing::Size(50, 50);
			this->pictureBox72->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox72->TabIndex = 72;
			this->pictureBox72->TabStop = false;
			this->pictureBox72->Click += gcnew System::EventHandler(this, &MyForm::pictureBox72_Click);
			// 
			// pictureBox73
			// 
			this->pictureBox73->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox73->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox73.ErrorImage")));
			this->pictureBox73->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox73.InitialImage")));
			this->pictureBox73->Location = System::Drawing::Point(47, 482);
			this->pictureBox73->Name = L"pictureBox73";
			this->pictureBox73->Size = System::Drawing::Size(50, 50);
			this->pictureBox73->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox73->TabIndex = 73;
			this->pictureBox73->TabStop = false;
			this->pictureBox73->Click += gcnew System::EventHandler(this, &MyForm::pictureBox73_Click);
			// 
			// pictureBox74
			// 
			this->pictureBox74->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox74->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox74.ErrorImage")));
			this->pictureBox74->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox74.InitialImage")));
			this->pictureBox74->Location = System::Drawing::Point(103, 482);
			this->pictureBox74->Name = L"pictureBox74";
			this->pictureBox74->Size = System::Drawing::Size(50, 50);
			this->pictureBox74->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox74->TabIndex = 74;
			this->pictureBox74->TabStop = false;
			this->pictureBox74->Click += gcnew System::EventHandler(this, &MyForm::pictureBox74_Click);
			// 
			// pictureBox75
			// 
			this->pictureBox75->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox75->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox75.ErrorImage")));
			this->pictureBox75->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox75.InitialImage")));
			this->pictureBox75->Location = System::Drawing::Point(159, 482);
			this->pictureBox75->Name = L"pictureBox75";
			this->pictureBox75->Size = System::Drawing::Size(50, 50);
			this->pictureBox75->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox75->TabIndex = 75;
			this->pictureBox75->TabStop = false;
			this->pictureBox75->Click += gcnew System::EventHandler(this, &MyForm::pictureBox75_Click);
			// 
			// pictureBox76
			// 
			this->pictureBox76->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox76->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox76.ErrorImage")));
			this->pictureBox76->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox76.InitialImage")));
			this->pictureBox76->Location = System::Drawing::Point(215, 482);
			this->pictureBox76->Name = L"pictureBox76";
			this->pictureBox76->Size = System::Drawing::Size(50, 50);
			this->pictureBox76->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox76->TabIndex = 76;
			this->pictureBox76->TabStop = false;
			this->pictureBox76->Click += gcnew System::EventHandler(this, &MyForm::pictureBox76_Click);
			// 
			// pictureBox77
			// 
			this->pictureBox77->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox77->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox77.ErrorImage")));
			this->pictureBox77->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox77.InitialImage")));
			this->pictureBox77->Location = System::Drawing::Point(271, 482);
			this->pictureBox77->Name = L"pictureBox77";
			this->pictureBox77->Size = System::Drawing::Size(50, 50);
			this->pictureBox77->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox77->TabIndex = 77;
			this->pictureBox77->TabStop = false;
			this->pictureBox77->Click += gcnew System::EventHandler(this, &MyForm::pictureBox77_Click);
			// 
			// pictureBox78
			// 
			this->pictureBox78->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox78->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox78.ErrorImage")));
			this->pictureBox78->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox78.InitialImage")));
			this->pictureBox78->Location = System::Drawing::Point(327, 482);
			this->pictureBox78->Name = L"pictureBox78";
			this->pictureBox78->Size = System::Drawing::Size(50, 50);
			this->pictureBox78->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox78->TabIndex = 78;
			this->pictureBox78->TabStop = false;
			this->pictureBox78->Click += gcnew System::EventHandler(this, &MyForm::pictureBox78_Click);
			// 
			// pictureBox79
			// 
			this->pictureBox79->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox79->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox79.ErrorImage")));
			this->pictureBox79->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox79.InitialImage")));
			this->pictureBox79->Location = System::Drawing::Point(383, 482);
			this->pictureBox79->Name = L"pictureBox79";
			this->pictureBox79->Size = System::Drawing::Size(50, 50);
			this->pictureBox79->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox79->TabIndex = 79;
			this->pictureBox79->TabStop = false;
			this->pictureBox79->Click += gcnew System::EventHandler(this, &MyForm::pictureBox79_Click);
			// 
			// pictureBox80
			// 
			this->pictureBox80->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox80->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox80.ErrorImage")));
			this->pictureBox80->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox80.InitialImage")));
			this->pictureBox80->Location = System::Drawing::Point(439, 482);
			this->pictureBox80->Name = L"pictureBox80";
			this->pictureBox80->Size = System::Drawing::Size(50, 50);
			this->pictureBox80->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox80->TabIndex = 80;
			this->pictureBox80->TabStop = false;
			this->pictureBox80->Click += gcnew System::EventHandler(this, &MyForm::pictureBox80_Click);
			// 
			// pictureBox81
			// 
			this->pictureBox81->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox81->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox81.ErrorImage")));
			this->pictureBox81->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox81.InitialImage")));
			this->pictureBox81->Location = System::Drawing::Point(495, 482);
			this->pictureBox81->Name = L"pictureBox81";
			this->pictureBox81->Size = System::Drawing::Size(50, 50);
			this->pictureBox81->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox81->TabIndex = 81;
			this->pictureBox81->TabStop = false;
			this->pictureBox81->Click += gcnew System::EventHandler(this, &MyForm::pictureBox81_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(706, 208);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(62, 17);
			this->radioButton1->TabIndex = 82;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Лёгкая";
			this->radioButton1->UseVisualStyleBackColor = false;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(706, 231);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(89, 17);
			this->radioButton2->TabIndex = 83;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Нормальная";
			this->radioButton2->UseVisualStyleBackColor = false;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->BackColor = System::Drawing::Color::Red;
			this->radioButton3->Location = System::Drawing::Point(706, 254);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(70, 17);
			this->radioButton3->TabIndex = 84;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Сложная";
			this->radioButton3->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(678, 51);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 85;
			this->button1->Text = L"Обновить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1013, 571);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->pictureBox81);
			this->Controls->Add(this->pictureBox80);
			this->Controls->Add(this->pictureBox79);
			this->Controls->Add(this->pictureBox78);
			this->Controls->Add(this->pictureBox77);
			this->Controls->Add(this->pictureBox76);
			this->Controls->Add(this->pictureBox75);
			this->Controls->Add(this->pictureBox74);
			this->Controls->Add(this->pictureBox73);
			this->Controls->Add(this->pictureBox72);
			this->Controls->Add(this->pictureBox71);
			this->Controls->Add(this->pictureBox70);
			this->Controls->Add(this->pictureBox69);
			this->Controls->Add(this->pictureBox68);
			this->Controls->Add(this->pictureBox67);
			this->Controls->Add(this->pictureBox66);
			this->Controls->Add(this->pictureBox65);
			this->Controls->Add(this->pictureBox64);
			this->Controls->Add(this->pictureBox63);
			this->Controls->Add(this->pictureBox62);
			this->Controls->Add(this->pictureBox61);
			this->Controls->Add(this->pictureBox60);
			this->Controls->Add(this->pictureBox59);
			this->Controls->Add(this->pictureBox58);
			this->Controls->Add(this->pictureBox57);
			this->Controls->Add(this->pictureBox56);
			this->Controls->Add(this->pictureBox55);
			this->Controls->Add(this->pictureBox54);
			this->Controls->Add(this->pictureBox53);
			this->Controls->Add(this->pictureBox52);
			this->Controls->Add(this->pictureBox51);
			this->Controls->Add(this->pictureBox50);
			this->Controls->Add(this->pictureBox49);
			this->Controls->Add(this->pictureBox48);
			this->Controls->Add(this->pictureBox47);
			this->Controls->Add(this->pictureBox46);
			this->Controls->Add(this->pictureBox45);
			this->Controls->Add(this->pictureBox44);
			this->Controls->Add(this->pictureBox43);
			this->Controls->Add(this->pictureBox42);
			this->Controls->Add(this->pictureBox41);
			this->Controls->Add(this->pictureBox40);
			this->Controls->Add(this->pictureBox39);
			this->Controls->Add(this->pictureBox38);
			this->Controls->Add(this->pictureBox37);
			this->Controls->Add(this->pictureBox36);
			this->Controls->Add(this->pictureBox35);
			this->Controls->Add(this->pictureBox34);
			this->Controls->Add(this->pictureBox33);
			this->Controls->Add(this->pictureBox32);
			this->Controls->Add(this->pictureBox31);
			this->Controls->Add(this->pictureBox30);
			this->Controls->Add(this->pictureBox29);
			this->Controls->Add(this->pictureBox28);
			this->Controls->Add(this->pictureBox27);
			this->Controls->Add(this->pictureBox26);
			this->Controls->Add(this->pictureBox25);
			this->Controls->Add(this->pictureBox24);
			this->Controls->Add(this->pictureBox23);
			this->Controls->Add(this->pictureBox22);
			this->Controls->Add(this->pictureBox21);
			this->Controls->Add(this->pictureBox20);
			this->Controls->Add(this->pictureBox19);
			this->Controls->Add(this->pictureBox18);
			this->Controls->Add(this->pictureBox17);
			this->Controls->Add(this->pictureBox16);
			this->Controls->Add(this->pictureBox15);
			this->Controls->Add(this->pictureBox14);
			this->Controls->Add(this->pictureBox13);
			this->Controls->Add(this->pictureBox12);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"Сапёр";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox35))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox36))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox37))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox38))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox39))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox40))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox41))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox42))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox43))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox44))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox45))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox46))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox47))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox48))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox49))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox50))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox51))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox52))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox53))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox54))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox55))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox56))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox57))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox58))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox59))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox60))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox61))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox62))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox63))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox64))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox65))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox66))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox67))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox68))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox69))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox70))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox71))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox72))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox73))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox74))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox75))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox76))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox77))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox78))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox79))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox80))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox81))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		click = 0;
		label1->Text = ("Счёт: " + click)->ToString();
		label1->Refresh();
		pictureBox1->Image = System::Drawing::Image::FromFile("fon.jpg");
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		a = generate_and_clear();
		//
		//лёгкий уровень сложности
		//
		if (radioButton1->Checked) {
			if (a == 1 || a == 2 || a == 3) {
				click++;
				pictureBox1->Image = System::Drawing::Image::FromFile("1.jpg");
				label1->Text = ("Счёт: " + click)->ToString();
				label1->Refresh();
			}
			else if (a == 4 || a == 5 || a == 6) {
				click = click + 2;
				pictureBox1->Image = System::Drawing::Image::FromFile("2.jpg");
				label1->Text = ("Счёт: " + click)->ToString();
				label1->Refresh();
			}
			else if (a == 7 || a == 8 || a == 9) {
				click = click + 3;
				pictureBox1->Image = System::Drawing::Image::FromFile("3.jpg");
				label1->Text = ("Счёт: " + click)->ToString();
				label1->Refresh();
			}
			else if (a == 10) {
				pictureBox1->Image = System::Drawing::Image::FromFile("krest.jpg");
				MessageBox::Show("Вы проиграли", "Game Over", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		//
		//нормальный уровень сложности
		//
		if (radioButton2->Checked) {
			if (a == 1 || a == 2) {
				click++;
				pictureBox1->Image = System::Drawing::Image::FromFile("1.jpg");
				label1->Text = ("Счёт: " + click)->ToString();
				label1->Refresh();
			}
			else if (a == 3 || a == 4) {
				click = click + 2;
				pictureBox1->Image = System::Drawing::Image::FromFile("2.jpg");
				label1->Text = ("Счёт: " + click)->ToString();
				label1->Refresh();
			}
			else if (a == 4 || a == 5) {
				click = click + 3;
				pictureBox1->Image = System::Drawing::Image::FromFile("3.jpg");
				label1->Text = ("Счёт: " + click)->ToString();
				label1->Refresh();
			}
			else if ( a == 6 || a == 7 || a == 8 || a == 9 || a == 10) {
				pictureBox1->Image = System::Drawing::Image::FromFile("krest.jpg");
				MessageBox::Show("Вы проиграли", "Game Over", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		//
		//сложный уровень сложности
		//
		if (radioButton3->Checked) {
			if (a == 1) {
				click++;
				pictureBox1->Image = System::Drawing::Image::FromFile("1.jpg");
				label1->Text = ("Счёт: " + click)->ToString();
				label1->Refresh();
			}
			if (a == 2) {
				click = click + 2;
				pictureBox1->Image = System::Drawing::Image::FromFile("2.jpg");
				label1->Text = ("Счёт: " + click)->ToString();
				label1->Refresh();
			}
			if (a == 3) {
				click = click + 3;
				pictureBox1->Image = System::Drawing::Image::FromFile("3.jpg");
				label1->Text = ("Счёт: " + click)->ToString();
				label1->Refresh();
			}
			else if (a == 4 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9 || a == 10) {
				pictureBox1->Image = System::Drawing::Image::FromFile("krest.jpg");
				MessageBox::Show("Вы проиграли", "Game Over", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox11_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox13_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox14_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox15_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox16_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox17_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox18_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox19_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox20_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox21_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox22_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox23_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox24_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox25_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox26_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox27_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox28_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox29_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox30_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox31_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox32_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox33_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox34_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox35_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox36_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox37_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox38_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox39_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox40_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox41_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox42_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox43_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox44_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox45_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox46_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox47_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox48_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox49_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox50_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox51_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox52_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox53_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox54_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox55_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox56_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox57_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox58_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox59_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox60_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox61_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox62_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox63_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox64_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox65_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox66_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox67_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox68_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox69_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox70_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox71_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox72_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox73_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox74_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox75_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox76_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox77_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox78_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox79_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox80_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox81_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
