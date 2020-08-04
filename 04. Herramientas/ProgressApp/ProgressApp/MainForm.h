#pragma once
#include "Helpers.h"
#include "CConstantes.h"

namespace ProgressApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnMental;
	private: System::Windows::Forms::Button^  btnPhysical;
	private: System::Windows::Forms::Button^  btnEmotional;
	protected:

	protected:


	private: System::Windows::Forms::ProgressBar^  pbMental;
	private: System::Windows::Forms::ProgressBar^  pbPhysical;
	private: System::Windows::Forms::ProgressBar^  pbEmotional;



	private: System::Windows::Forms::Label^  lbTitulo;

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
			this->btnMental = (gcnew System::Windows::Forms::Button());
			this->btnPhysical = (gcnew System::Windows::Forms::Button());
			this->btnEmotional = (gcnew System::Windows::Forms::Button());
			this->pbMental = (gcnew System::Windows::Forms::ProgressBar());
			this->pbPhysical = (gcnew System::Windows::Forms::ProgressBar());
			this->pbEmotional = (gcnew System::Windows::Forms::ProgressBar());
			this->lbTitulo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnMental
			// 
			this->btnMental->Location = System::Drawing::Point(7, 97);
			this->btnMental->Name = L"btnMental";
			this->btnMental->Size = System::Drawing::Size(75, 23);
			this->btnMental->TabIndex = 0;
			this->btnMental->Text = L"Mental";
			this->btnMental->UseVisualStyleBackColor = true;
			this->btnMental->Click += gcnew System::EventHandler(this, &MainForm::btnMental_Click);
			// 
			// btnPhysical
			// 
			this->btnPhysical->Location = System::Drawing::Point(7, 202);
			this->btnPhysical->Name = L"btnPhysical";
			this->btnPhysical->Size = System::Drawing::Size(75, 23);
			this->btnPhysical->TabIndex = 1;
			this->btnPhysical->Text = L"Physical";
			this->btnPhysical->UseVisualStyleBackColor = true;
			this->btnPhysical->Click += gcnew System::EventHandler(this, &MainForm::btnPhysical_Click);
			// 
			// btnEmotional
			// 
			this->btnEmotional->Location = System::Drawing::Point(7, 292);
			this->btnEmotional->Name = L"btnEmotional";
			this->btnEmotional->Size = System::Drawing::Size(75, 23);
			this->btnEmotional->TabIndex = 2;
			this->btnEmotional->Text = L"Emotional";
			this->btnEmotional->UseVisualStyleBackColor = true;
			this->btnEmotional->Click += gcnew System::EventHandler(this, &MainForm::btnEmotional_Click);
			// 
			// pbMental
			// 
			this->pbMental->Location = System::Drawing::Point(88, 85);
			this->pbMental->Name = L"pbMental";
			this->pbMental->Size = System::Drawing::Size(1002, 49);
			this->pbMental->TabIndex = 3;
			// 
			// pbPhysical
			// 
			this->pbPhysical->Location = System::Drawing::Point(88, 186);
			this->pbPhysical->Name = L"pbPhysical";
			this->pbPhysical->Size = System::Drawing::Size(1002, 51);
			this->pbPhysical->TabIndex = 4;
			// 
			// pbEmotional
			// 
			this->pbEmotional->Location = System::Drawing::Point(88, 277);
			this->pbEmotional->Name = L"pbEmotional";
			this->pbEmotional->Size = System::Drawing::Size(1002, 50);
			this->pbEmotional->TabIndex = 5;
			// 
			// lbTitulo
			// 
			this->lbTitulo->AutoSize = true;
			this->lbTitulo->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTitulo->Location = System::Drawing::Point(402, 9);
			this->lbTitulo->Name = L"lbTitulo";
			this->lbTitulo->Size = System::Drawing::Size(373, 38);
			this->lbTitulo->TabIndex = 6;
			this->lbTitulo->Text = L"Progreso del entrenamiento";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1147, 383);
			this->Controls->Add(this->lbTitulo);
			this->Controls->Add(this->pbEmotional);
			this->Controls->Add(this->pbPhysical);
			this->Controls->Add(this->pbMental);
			this->Controls->Add(this->btnEmotional);
			this->Controls->Add(this->btnPhysical);
			this->Controls->Add(this->btnMental);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::eventoCerrandoAplicacion);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		int valorMental = 0, valorFisico = 0, valorEmocional = 0;
		if (!CHelpers::VerificarExistenciaArchivo(CConstantes::nombreArchivo)) {
			CHelpers::CrearArchivo(CConstantes::nombreArchivo);
		}
		else {
			CHelpers::LeerArchivoProgreso(CConstantes::nombreArchivo, valorMental, valorFisico, valorEmocional);
		}

		pbMental->Value = valorMental;
		pbPhysical->Value = valorFisico;
		pbEmotional->Value = valorEmocional;

	}

void IncrementarBarraProgreso(System::Windows::Forms::ProgressBar^ barraProgreso, int incremento) {
	barraProgreso->Value += incremento;
}

private: System::Void btnMental_Click(System::Object^  sender, System::EventArgs^  e) {
	IncrementarBarraProgreso(pbMental, CConstantes::INCREMENTO);
}
private: System::Void btnPhysical_Click(System::Object^  sender, System::EventArgs^  e) {
	IncrementarBarraProgreso(pbPhysical, CConstantes::INCREMENTO);
}
private: System::Void btnEmotional_Click(System::Object^  sender, System::EventArgs^  e) {
	IncrementarBarraProgreso(pbEmotional, CConstantes::INCREMENTO);
}




private: System::Void eventoCerrandoAplicacion(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	CHelpers::EscribirArchivoProgreso(CConstantes::nombreArchivo, pbMental->Value, pbPhysical->Value, pbEmotional->Value);
}
};
}
