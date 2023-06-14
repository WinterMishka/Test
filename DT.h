#pragma once
#include <cstdlib>
#include <iostream>

namespace WinterMishka {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для DT
	/// </summary>
	public ref class DT : public System::Windows::Forms::Form
	{
	public:
	private:
		String^ _price_DT;
	public:
		property String^ Value1 {
			void set(String^ price_DT) { _price_DT = price_DT; }
			String^ get() { return _price_DT; }
		}
		DT(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			DT::StartPosition = FormStartPosition::CenterScreen;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DT()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.875F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(415, 62);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(714, 45);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Добро пожаловать на заправочную колонку №";
			this->label1->Click += gcnew System::EventHandler(this, &DT::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(473, 332);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(185, 31);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &DT::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 19.875F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(73, 178);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(622, 64);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Введите количество литров:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.875F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(203, 254);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(395, 45);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Цена 1 литра топлива = ";
			this->label3->Click += gcnew System::EventHandler(this, &DT::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(216, 421);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 25);
			this->label4->TabIndex = 4;
			this->label4->Text = L"label4";
			this->label4->Click += gcnew System::EventHandler(this, &DT::label4_Click);
			// 
			// DT
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1600, 1154);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"DT";
			this->Text = L"DT";
			this->Load += gcnew System::EventHandler(this, &DT::DT_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int litr;
	private: System::Void DT_Load(System::Object^ sender, System::EventArgs^ e) {
		int a = rand() % 5 + 1;
		label3->Text = "Цена за 1 литр топлива = " + _price_DT;
		label1->Text = System::String::Concat("Добро пожаловать на заправочную колонку №" + a);
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//litr = Convert::ToInt32(textBox1->Text);
	//float sum = litr * priceDT;
	//label4->Text = ("Итого к оплате = " + (sum))->ToString();
	//label4->Refresh();
}
};
}
