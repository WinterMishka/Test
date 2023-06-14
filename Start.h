#pragma once
#include "GasStation.h"
#include "DT.h"
#include <wininet.h>
#pragma comment(lib, "wininet.lib")

namespace WinterMishka {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::OleDb;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Start
	/// </summary>
	public ref class Start : public System::Windows::Forms::Form
	{
	public:
		Start(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			Start::StartPosition = FormStartPosition::CenterScreen;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Start()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1496, 23);
			this->button1->Margin = System::Windows::Forms::Padding(6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 77);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Start::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(306, 479);
			this->button2->Margin = System::Windows::Forms::Padding(6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(1000, 154);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Заправиться!";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Start::button2_Click);
			// 
			// Start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1600, 1062);
			this->ControlBox = false;
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(6);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Start";
			this->Text = L"Start";
			this->Load += gcnew System::EventHandler(this, &Start::Start_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	String^ value;
	String^ price_AI92;
	String^ price_AI95;
	String^ price_AI98;
	public:
		static String^ price_DT;
	private: System::Void Start_Load(System::Object^ sender, System::EventArgs^ e) {
		if (InternetCheckConnection(L"http://www.google.com", FLAG_ICC_FORCE_CONNECTION, 0)) {
			MessageBox::Show("Интернет успешно подключен!");
			String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\artyo\\source\\repos\\WinterMishka\\BD.accdb;";
			OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
			OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT * FROM [password]", connection);
			if (connection->State == ConnectionState::Closed) {
				MessageBox::Show("База данных успешно подключена!");
				connection->Open();
				OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT * FROM [password]", connection);
				OleDbDataAdapter^ adapter2 = gcnew OleDbDataAdapter("SELECT * FROM [datasource]", connection);
				DataTable^ dataTable = gcnew DataTable();
				DataTable^ dataTable2 = gcnew DataTable();
				adapter->Fill(dataTable);
				adapter2->Fill(dataTable2);
				value = dataTable->Rows[0]->default[1]->ToString();
				price_AI92 = dataTable2->Rows[0]->default[2]->ToString();
				price_AI95 = dataTable2->Rows[1]->default[2]->ToString();
				price_AI98 = dataTable2->Rows[2]->default[2]->ToString();
				price_DT = dataTable2->Rows[3]->default[2]->ToString();
				connection->Close();
			}
			else {
				MessageBox::Show("Не удалось установить соединение с базой данных.");
			}
		}
		else {
			MessageBox::Show("Отсутствует подключение к интернету!");
			Application::Exit();
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		GasStation^ f1 = gcnew GasStation();
		f1->Value = value;
		f1->Owner = this;
		f1->Show();
		this->Hide();
	}
};
}
