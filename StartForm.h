#pragma once

#include "Login.h"
#include "LoginAdmin.h"
#include <WinBase.h>
#include "About.h"

namespace adaptive_tester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public: GlobalVars^ gv = gcnew GlobalVars();
	private: System::Windows::Forms::SaveFileDialog^  save_dlg;
	public:

	private: String ^ path_to_ini = Path::GetDirectoryName(Application::ExecutablePath) + "\\test.ini";
	public: StartForm(void)
	{
		InitializeComponent();

		try {
			gv->password = "";
			StreamReader^ din = File::OpenText(path_to_ini);
			String^ delimiter_str = "=";
			array<Char>^ delimiter = delimiter_str->ToCharArray();
			array<String^>^ words;

			String^ str;
			int count = 0;
			while ((str = din->ReadLine()) != nullptr)
			{
				words = str->Split(delimiter);
				if (words[0] == "password")
				{
					gv->password = words[1];
				}
				else
				{
					TestList tl;
					tl.test_name = words[0];
					tl.test_path = words[1];
					gv->test_list->Add(tl);
				}
			}
			din->Close();

		}
		catch (Exception^ e)
		{
			MessageBox::Show("������, ��� �� � ������ ��� ���������� ����������, ��� ��� INI ���� �� ��� ������. ������ ���� ����� ������� ����� ������ �� ����������!");
		}
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnExit;
	protected: 
	private: System::Windows::Forms::Button^  btnRunTest;
	private: System::Windows::Forms::Button^  btnCreateTest;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  creaet_test_ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  createtestToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  start_test_ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  exit_ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  help_ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  manua_lToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  about_ToolStripMenuItem;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnRunTest = (gcnew System::Windows::Forms::Button());
			this->btnCreateTest = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->creaet_test_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createtestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->start_test_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exit_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->help_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manua_lToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->about_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->save_dlg = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(35, 146);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(215, 31);
			this->btnExit->TabIndex = 2;
			this->btnExit->Text = L"�����";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &StartForm::btnExit_Click);
			// 
			// btnRunTest
			// 
			this->btnRunTest->Location = System::Drawing::Point(35, 85);
			this->btnRunTest->Name = L"btnRunTest";
			this->btnRunTest->Size = System::Drawing::Size(215, 45);
			this->btnRunTest->TabIndex = 1;
			this->btnRunTest->Text = L"������ ����";
			this->btnRunTest->UseVisualStyleBackColor = true;
			this->btnRunTest->Click += gcnew System::EventHandler(this, &StartForm::btnRunTest_Click);
			// 
			// btnCreateTest
			// 
			this->btnCreateTest->Location = System::Drawing::Point(35, 34);
			this->btnCreateTest->Name = L"btnCreateTest";
			this->btnCreateTest->Size = System::Drawing::Size(215, 45);
			this->btnCreateTest->TabIndex = 0;
			this->btnCreateTest->Text = L"������� ����";
			this->btnCreateTest->UseVisualStyleBackColor = true;
			this->btnCreateTest->Click += gcnew System::EventHandler(this, &StartForm::btnCreateTest_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->creaet_test_ToolStripMenuItem,
					this->help_ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->TabStop = true;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// creaet_test_ToolStripMenuItem
			// 
			this->creaet_test_ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->createtestToolStripMenuItem,
					this->toolStripMenuItem1, this->start_test_ToolStripMenuItem, this->toolStripMenuItem2, this->exit_ToolStripMenuItem
			});
			this->creaet_test_ToolStripMenuItem->Name = L"creaet_test_ToolStripMenuItem";
			this->creaet_test_ToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->creaet_test_ToolStripMenuItem->Text = L"����";
			// 
			// createtestToolStripMenuItem
			// 
			this->createtestToolStripMenuItem->Name = L"createtestToolStripMenuItem";
			this->createtestToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->createtestToolStripMenuItem->Text = L"������� ����";
			this->createtestToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::btnCreateTest_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(139, 6);
			// 
			// start_test_ToolStripMenuItem
			// 
			this->start_test_ToolStripMenuItem->Name = L"start_test_ToolStripMenuItem";
			this->start_test_ToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->start_test_ToolStripMenuItem->Text = L"������ ����";
			this->start_test_ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::btnRunTest_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(139, 6);
			// 
			// exit_ToolStripMenuItem
			// 
			this->exit_ToolStripMenuItem->Name = L"exit_ToolStripMenuItem";
			this->exit_ToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->exit_ToolStripMenuItem->Text = L"�����";
			this->exit_ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::btnExit_Click);
			// 
			// help_ToolStripMenuItem
			// 
			this->help_ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->manua_lToolStripMenuItem,
					this->about_ToolStripMenuItem
			});
			this->help_ToolStripMenuItem->Name = L"help_ToolStripMenuItem";
			this->help_ToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->help_ToolStripMenuItem->Text = L"������";
			// 
			// manua_lToolStripMenuItem
			// 
			this->manua_lToolStripMenuItem->Name = L"manua_lToolStripMenuItem";
			this->manua_lToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->manua_lToolStripMenuItem->Text = L"����������� ������������";
			this->manua_lToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::manua_lToolStripMenuItem_Click);
			// 
			// about_ToolStripMenuItem
			// 
			this->about_ToolStripMenuItem->Name = L"about_ToolStripMenuItem";
			this->about_ToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->about_ToolStripMenuItem->Text = L"� ���������";
			this->about_ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::about_ToolStripMenuItem_Click);
			// 
			// save_dlg
			// 
			this->save_dlg->Filter = L"DOCX |*.docx";
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 186);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnRunTest);
			this->Controls->Add(this->btnCreateTest);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"StartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Adaptive tester";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StartForm::StartForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void btnCreateTest_Click(System::Object^  sender, System::EventArgs^  e) {
		Form^ loginAdmin = gcnew LoginAdmin(this, gv);
		loginAdmin->Show();
		this->Hide();
		}
	private: System::Void btnRunTest_Click(System::Object^  sender, System::EventArgs^  e) {
		Form^ loginForm = gcnew Login(this, gv);
		//this->Hide();
	}
	private: System::Void StartForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		try
		{
			StreamWriter^ sw = gcnew StreamWriter(path_to_ini);
			sw->WriteLine("password=" + gv->password);

			for (int i = 0; i < gv->test_list->Count; i++)
			{
				sw->WriteLine(gv->test_list[i].test_name + "=" + gv->test_list[i].test_path);
			}
			sw->Close();
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message);
		}
	}
	private: System::Void about_ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Form^ about = gcnew About();
		about->ShowDialog();
	}
	private: System::Void manua_lToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			System::Net::WebClient ^webClient = gcnew System::Net::WebClient();
			String^ _URL = "https://drive.google.com/uc?authuser=0&id=1ddOIoWDrjmQaUTatTFkRwFd_mpd8pw8x&export=download";

			this->save_dlg->ShowDialog();

			if (save_dlg->FileName != "")
			{
				webClient->DownloadFile(_URL, save_dlg->FileName);
			}
			delete webClient;
		}
		catch (System::Exception^ e)
		{
			MessageBox::Show(e->Message);
		}
	}
};
}
