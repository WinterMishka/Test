#pragma once
#include "GasStation.h"
#include "DT.h"
#include "AI_92.h"
#include "AI_95.h"
#include "AI_98.h"
#include "Administrator.h"

int litr;
int rub_1 = 1, rub_2 = 2, rub_5 = 5, rub_10 = 10, rub_20 = 20, rub_50 = 50, rub_100 = 100;
float rub_01 = 0.01, rub_02 = 0.02, rub_05 = 0.05, rub_010 = 0.1, rub_020 = 0.2, rub_050 = 0.5;
float price_dt = 2.36, price_ai92 = 2.26, price_ai95 = 2.36, price_ai98 = 2.58;
float sum_dt = 0, sum_ai92 = 0, sum_ai95 = 0, sum_ai98 = 0;
float sdacha = 0;
float oplata = 0;

namespace Kursach {

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
		DataTable^ dt;
		Start(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			Start::StartPosition = FormStartPosition::CenterScreen; //центр экрана (0; 0)
			dt = gcnew DataTable();
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
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Start::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(208, 298);
			this->button1->Margin = System::Windows::Forms::Padding(6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(774, 144);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Заправиться!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Start::button1_Click);
			// 
			// button2
			// 
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(1126, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(60, 60);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Start::button2_Click);
			// 
			// Start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 769);
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
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		GasStation^ f1 = gcnew GasStation();
		f1->Show();							//Переход из Start в GasStation
		Start::Hide();
	}
	public: System::Void Start_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;" + "Data Source=C:\\Users\\artyo\\source\\repos\\Kursach\\BD.xlsx;" +
			"Extended Properties=\"Excel 12.0 Xml;HDR=YES;IMEX=1\";";
		OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
		connection->Open();  OleDbDataAdapter^ sda = gcnew OleDbDataAdapter("SELECT * FROM [BD$]", connection);
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	};
}
