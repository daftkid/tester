#pragma once


namespace adaptive_tester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{

	public: Form^ main = gcnew Form;

	public:
		Login(Form^ main)
		{
			InitializeComponent();
			this->main = main;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  start_testing;
	protected: 
	private: System::Windows::Forms::TextBox^  group;
	private: System::Windows::Forms::TextBox^  student_name;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  l_group;
	private: System::Windows::Forms::Label^  l_name;


	private: System::Windows::Forms::Button^  back_to_start;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->start_testing = (gcnew System::Windows::Forms::Button());
			this->group = (gcnew System::Windows::Forms::TextBox());
			this->student_name = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->l_group = (gcnew System::Windows::Forms::Label());
			this->l_name = (gcnew System::Windows::Forms::Label());
			this->back_to_start = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// start_testing
			// 
			this->start_testing->Location = System::Drawing::Point(16, 116);
			this->start_testing->Name = L"start_testing";
			this->start_testing->Size = System::Drawing::Size(256, 47);
			this->start_testing->TabIndex = 11;
			this->start_testing->Text = L"������ ����";
			this->start_testing->UseVisualStyleBackColor = true;
			this->start_testing->Click += gcnew System::EventHandler(this, &Login::start_testing_Click);
			// 
			// group
			// 
			this->group->Location = System::Drawing::Point(129, 48);
			this->group->Name = L"group";
			this->group->Size = System::Drawing::Size(143, 20);
			this->group->TabIndex = 10;
			// 
			// student_name
			// 
			this->student_name->Location = System::Drawing::Point(129, 22);
			this->student_name->Name = L"student_name";
			this->student_name->Size = System::Drawing::Size(143, 20);
			this->student_name->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(73, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 8;
			// 
			// l_group
			// 
			this->l_group->AutoSize = true;
			this->l_group->Location = System::Drawing::Point(13, 51);
			this->l_group->Name = L"l_group";
			this->l_group->Size = System::Drawing::Size(45, 13);
			this->l_group->TabIndex = 7;
			this->l_group->Text = L"������:";
			// 
			// l_name
			// 
			this->l_name->AutoSize = true;
			this->l_name->Location = System::Drawing::Point(13, 25);
			this->l_name->Name = L"l_name";
			this->l_name->Size = System::Drawing::Size(87, 13);
			this->l_name->TabIndex = 6;
			this->l_name->Text = L"�������, ���:";
			// 
			// back_to_start
			// 
			this->back_to_start->Location = System::Drawing::Point(16, 172);
			this->back_to_start->Name = L"back_to_start";
			this->back_to_start->Size = System::Drawing::Size(256, 31);
			this->back_to_start->TabIndex = 12;
			this->back_to_start->Text = L"���������";
			this->back_to_start->UseVisualStyleBackColor = true;
			this->back_to_start->Click += gcnew System::EventHandler(this, &Login::back_to_start_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(129, 74);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(143, 21);
			this->comboBox1->TabIndex = 13;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"�������� ����:";
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 214);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->back_to_start);
			this->Controls->Add(this->start_testing);
			this->Controls->Add(this->group);
			this->Controls->Add(this->student_name);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->l_group);
			this->Controls->Add(this->l_name);
			this->Name = L"Login";
			this->Text = L"Login";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Login::Login_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void Login_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		this->main->Show();
	}
	private: System::Void back_to_start_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void start_testing_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->group->Text == "" || this->student_name->Text == "")
		{
			MessageBox::Show("��������� ��� ����!");
			if (this->student_name->Text == "")
			{
				this->student_name->Focus();
			}
			else
			{
				this->group->Focus();
			}
			return;
		}
	}
};
}
