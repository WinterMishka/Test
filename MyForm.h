#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <msclr/marshal_cppstd.h>
#include <algorithm>

namespace KursovayaMelnikov {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для redaktirovanie
	/// </summary>
	public ref class redaktirovanie : public System::Windows::Forms::Form
	{
	public:
		redaktirovanie(void)
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
		~redaktirovanie()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(40, 70);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(228, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &redaktirovanie::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(40, 96);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 63);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Записать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &redaktirovanie::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(88, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Введите марку автомобиля:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(160, 96);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 63);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Удалить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &redaktirovanie::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 305);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(256, 147);
			this->listBox1->TabIndex = 4;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &redaktirovanie::listBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(213, 263);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(207, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Текущие марки и модели автомобилей";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(385, 305);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(256, 147);
			this->listBox2->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(401, 45);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(157, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Введите модель автомобиля:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(366, 70);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(228, 20);
			this->textBox2->TabIndex = 8;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(366, 96);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(108, 63);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Записать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &redaktirovanie::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(486, 96);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(108, 63);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Удалить";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// redaktirovanie
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(653, 513);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"redaktirovanie";
			this->Text = L"redaktirovanie";
			this->Load += gcnew System::EventHandler(this, &redaktirovanie::redaktirovanie_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//ДОБАВИТЬ МАРКУ АВТОМОБИЛЯ
		ifstream file;
		file.open("C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\marki.txt");
		string line;
		vector<string> lines;
		while (getline(file, line)) {
			lines.push_back(line);
		}
		file.close();
		string text = msclr::interop::marshal_as<std::string>(textBox1->Text);
		if (find(lines.begin(), lines.end(), text) != lines.end()) {
			MessageBox::Show("Данная марка уже занесена в базу!");
		}
		else {
			ofstream outfile;
			outfile.open("C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\marki.txt", ios_base::app);
			outfile << text << endl;
			outfile.close();
			listBox1->DataSource = System::IO::File::ReadAllLines("C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\marki.txt");
			listBox1->Refresh();
			ofstream newfile;
			newfile.open("C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\Modeli\\" + text + ".txt");
			newfile.close();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//УДАЛИТЬ МАРКУ АВТОМОБИЛЯ
		ifstream file;
		file.open("C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\marki.txt");
		string line;
		vector<string> lines;
		while (getline(file, line)) {
			lines.push_back(line);
		}
		file.close();
		string text = msclr::interop::marshal_as<std::string>(textBox1->Text);
		auto it = find(lines.begin(), lines.end(), text);
		if (it != lines.end()) {
			lines.erase(it);
			ofstream outfile;
			outfile.open("C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\marki.txt");
			for (const auto& line : lines) {
				outfile << line << endl;
			}
			outfile.close();
			remove(("C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\Modeli\\" + text + ".txt").c_str());
			listBox1->DataSource = System::IO::File::ReadAllLines("C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\marki.txt");
			listBox1->Refresh();
		}
		else {
			MessageBox::Show("Введённая марка не обнаружена в базе!");
		}
	}
	private: System::Void redaktirovanie_Load(System::Object^ sender, System::EventArgs^ e) {
		listBox1->DataSource = System::IO::File::ReadAllLines("C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\marki.txt");
		listBox1->Refresh();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		//ДОБАВИТЬ МОДЕЛЬ АВТОМОБИЛЯ
		string text = msclr::interop::marshal_as<std::string>(textBox2->Text);
		string selectedFile = msclr::interop::marshal_as<std::string>(listBox1->SelectedItem->ToString());
		ifstream file;
		file.open("C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\Modeli\\" + selectedFile + ".txt");
		string line;
		vector<string> lines;
		while (getline(file, line)) {
			lines.push_back(line);
		}
		file.close();
		if (find(lines.begin(), lines.end(), text) != lines.end()) {
			MessageBox::Show("Данная модель уже занесена в базу!");
		}
		else {
			ofstream outfile;
			outfile.open("C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\Modeli\\" + selectedFile + ".txt", ios_base::app);
			outfile << text << endl;
			outfile.close();
			string selectedFile = msclr::interop::marshal_as<std::string>(listBox1->SelectedItem->ToString());
			string path = "C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\Modeli\\" + selectedFile + ".txt";
			listBox2->DataSource = System::IO::File::ReadAllLines(gcnew String(path.c_str()));
			listBox2->Refresh();
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
				//УДАЛИТЬ МОДЕЛЬ АВТОМОБИЛЯ
		string selectedBrand = msclr::interop::marshal_as<std::string>(listBox1->SelectedItem->ToString());
		string selectedModel = msclr::interop::marshal_as<std::string>(listBox2->SelectedItem->ToString());
		string path = "C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\Modeli\\" + selectedBrand + ".txt";
		ifstream file;
		file.open(path);
		string line;
		vector<string> lines;
		while (getline(file, line)) {
			lines.push_back(line);
		}
		file.close();
		lines.erase(remove(lines.begin(), lines.end(), selectedModel), lines.end());
		ofstream outfile;
		outfile.open(path);
		for (const auto& line : lines) {
			outfile << line << endl;
			string selectedFile = msclr::interop::marshal_as<std::string>(listBox1->SelectedItem->ToString());
			string path = "C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\Modeli\\" + selectedFile + ".txt";
			listBox2->DataSource = System::IO::File::ReadAllLines(gcnew String(path.c_str()));

		}
		outfile.close();
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		string selectedFile = msclr::interop::marshal_as<std::string>(listBox1->SelectedItem->ToString());
		string path = "C:\\Users\\artyo\\source\\repos\\Kursovaya_Melnikov\\Modeli\\" + selectedFile + ".txt";
		listBox2->DataSource = System::IO::File::ReadAllLines(gcnew String(path.c_str()));
	}
};
}
