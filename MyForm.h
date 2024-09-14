#pragma once
#include "BubbleSort.h"

namespace MUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Titulo;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ array;

	private: System::Windows::Forms::Button^ Bbs;
	protected:

	protected:

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
			this->Titulo = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->array = (gcnew System::Windows::Forms::Label());
			this->Bbs = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Titulo
			// 
			this->Titulo->AutoSize = true;
			this->Titulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Titulo->Location = System::Drawing::Point(293, 9);
			this->Titulo->Name = L"Titulo";
			this->Titulo->Size = System::Drawing::Size(411, 37);
			this->Titulo->TabIndex = 0;
			this->Titulo->Text = L"Metodos de ordenamiento";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(300, 77);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(404, 26);
			this->textBox1->TabIndex = 1;
			// 
			// array
			// 
			this->array->AutoSize = true;
			this->array->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->array->Location = System::Drawing::Point(354, 131);
			this->array->Name = L"array";
			this->array->Size = System::Drawing::Size(297, 26);
			this->array->TabIndex = 2;
			this->array->Text = L"Ingrese tamaño del arreglo";
			// 
			// Bbs
			// 
			this->Bbs->Location = System::Drawing::Point(12, 235);
			this->Bbs->Name = L"Bbs";
			this->Bbs->Size = System::Drawing::Size(124, 32);
			this->Bbs->TabIndex = 3;
			this->Bbs->Text = L"Bubble Sort";
			this->Bbs->UseVisualStyleBackColor = true;
			this->Bbs->Click += gcnew System::EventHandler(this, &MyForm::Bbs_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(993, 366);
			this->Controls->Add(this->Bbs);
			this->Controls->Add(this->array);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Titulo);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Bbs_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Obtener el tamaño del arreglo desde el TextBox
			int tam = Convert::ToInt32(textBox1->Text);

			// Crear una instancia de la clase BubbleSort
			BubbleSort sorter(tam);

			// Obtener el arreglo desordenado y mostrarlo en la etiqueta
			auto unsortedArray = sorter.GetUnsortedArray();
			String^ unsortedStr = "Desordenado: ";
			for (auto n : unsortedArray) {
				unsortedStr += n.ToString() + " ";
			}
			array->Text = unsortedStr;

			// Ejecutar Bubble Sort
			auto sortedArray = sorter.Sort();

			// Mostrar el arreglo ordenado en la etiqueta
			String^ sortedStr = "Ordenado: ";
			for (auto n : sortedArray) {
				sortedStr += n.ToString() + " ";
			}
			array->Text += "\n" + sortedStr;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
