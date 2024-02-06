#pragma once
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>

namespace Project1 {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	struct Process {
		int id;
		int arrivalTime;
		int burstTime;
		int startTime;
		int completionTime;
		int turnaroundTime;
		int waitingTime;
		int responseTime;
		int priority;
		int remainingTime;
	};

	// Comparison functions for sorting processes
	bool compareArrival(Process p1, Process p2) {
		return p1.arrivalTime < p2.arrivalTime;
	}

	bool compareID(Process p1, Process p2) {
		return p1.id < p2.id;
	}

	// Comparison functions for sorting processes
	bool sortByArrival(const Process& a, const Process& b) {
		return a.arrivalTime < b.arrivalTime;
	}

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		String^ arrive;


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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cbbAlgo;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtboxArrival;
	private: System::Windows::Forms::TextBox^ txtboxBurst;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnSubmit;




	private: System::Windows::Forms::ListBox^ lstboxDisplay;

	private: System::Windows::Forms::Label^ lstTitle;
	private: System::Windows::Forms::TextBox^ txtboxPriority;
	private: System::Windows::Forms::Label^ lblPriority;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ lblATT;
	private: System::Windows::Forms::Label^ lblAWT;


	private: System::Windows::Forms::TextBox^ txtboxATT;
	private: System::Windows::Forms::TextBox^ txtboxAWT;
	private: System::Windows::Forms::TextBox^ txtboxCPU;
	private: System::Windows::Forms::Label^ lblCPU;
	private: System::Windows::Forms::GroupBox^ groupBox2;















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbbAlgo = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtboxArrival = (gcnew System::Windows::Forms::TextBox());
			this->txtboxBurst = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->lstboxDisplay = (gcnew System::Windows::Forms::ListBox());
			this->lstTitle = (gcnew System::Windows::Forms::Label());
			this->txtboxPriority = (gcnew System::Windows::Forms::TextBox());
			this->lblPriority = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lblATT = (gcnew System::Windows::Forms::Label());
			this->lblAWT = (gcnew System::Windows::Forms::Label());
			this->txtboxATT = (gcnew System::Windows::Forms::TextBox());
			this->txtboxAWT = (gcnew System::Windows::Forms::TextBox());
			this->txtboxCPU = (gcnew System::Windows::Forms::TextBox());
			this->lblCPU = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(92, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Algorithm";
			// 
			// cbbAlgo
			// 
			this->cbbAlgo->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->cbbAlgo->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->cbbAlgo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbbAlgo->ForeColor = System::Drawing::SystemColors::InfoText;
			this->cbbAlgo->FormattingEnabled = true;
			this->cbbAlgo->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"FCFS (First Come First Serve)", L"NPP (Non-Preemptive Priority)",
					L"SRTF (Shortest Remaining Time First)"
			});
			this->cbbAlgo->Location = System::Drawing::Point(95, 96);
			this->cbbAlgo->Name = L"cbbAlgo";
			this->cbbAlgo->Size = System::Drawing::Size(185, 21);
			this->cbbAlgo->TabIndex = 1;
			this->cbbAlgo->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cbbAlgo_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(95, 139);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Arrival Time:";
			// 
			// txtboxArrival
			// 
			this->txtboxArrival->AccessibleDescription = L"";
			this->txtboxArrival->Location = System::Drawing::Point(95, 156);
			this->txtboxArrival->Name = L"txtboxArrival";
			this->txtboxArrival->Size = System::Drawing::Size(185, 20);
			this->txtboxArrival->TabIndex = 3;
			// 
			// txtboxBurst
			// 
			this->txtboxBurst->Location = System::Drawing::Point(95, 217);
			this->txtboxBurst->Name = L"txtboxBurst";
			this->txtboxBurst->Size = System::Drawing::Size(185, 20);
			this->txtboxBurst->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(95, 200);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Burst Time:";
			// 
			// btnSubmit
			// 
			this->btnSubmit->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubmit->ForeColor = System::Drawing::Color::White;
			this->btnSubmit->Location = System::Drawing::Point(95, 313);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(75, 23);
			this->btnSubmit->TabIndex = 6;
			this->btnSubmit->Text = L"Solve";
			this->btnSubmit->UseVisualStyleBackColor = false;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &MyForm::btnSubmit_Click);
			// 
			// lstboxDisplay
			// 
			this->lstboxDisplay->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstboxDisplay->FormattingEnabled = true;
			this->lstboxDisplay->ItemHeight = 15;
			this->lstboxDisplay->Location = System::Drawing::Point(378, 96);
			this->lstboxDisplay->Name = L"lstboxDisplay";
			this->lstboxDisplay->Size = System::Drawing::Size(719, 169);
			this->lstboxDisplay->TabIndex = 9;
			this->lstboxDisplay->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::lstboxDisplay_SelectedIndexChanged);
			// 
			// lstTitle
			// 
			this->lstTitle->AutoSize = true;
			this->lstTitle->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstTitle->ForeColor = System::Drawing::Color::White;
			this->lstTitle->Location = System::Drawing::Point(375, 78);
			this->lstTitle->Name = L"lstTitle";
			this->lstTitle->Size = System::Drawing::Size(59, 15);
			this->lstTitle->TabIndex = 10;
			this->lstTitle->Text = L"Algorithm";
			// 
			// txtboxPriority
			// 
			this->txtboxPriority->Location = System::Drawing::Point(95, 273);
			this->txtboxPriority->Name = L"txtboxPriority";
			this->txtboxPriority->Size = System::Drawing::Size(185, 20);
			this->txtboxPriority->TabIndex = 12;
			// 
			// lblPriority
			// 
			this->lblPriority->AutoSize = true;
			this->lblPriority->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPriority->ForeColor = System::Drawing::Color::White;
			this->lblPriority->Location = System::Drawing::Point(95, 256);
			this->lblPriority->Name = L"lblPriority";
			this->lblPriority->Size = System::Drawing::Size(45, 13);
			this->lblPriority->TabIndex = 11;
			this->lblPriority->Text = L"Priority:";
			// 
			// groupBox1
			// 
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(61, 36);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(254, 319);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Input";
			// 
			// lblATT
			// 
			this->lblATT->AutoSize = true;
			this->lblATT->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblATT->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblATT->ForeColor = System::Drawing::Color::White;
			this->lblATT->Location = System::Drawing::Point(375, 283);
			this->lblATT->Name = L"lblATT";
			this->lblATT->Size = System::Drawing::Size(184, 18);
			this->lblATT->TabIndex = 15;
			this->lblATT->Text = L"Ave. Turnaround Time";
			// 
			// lblAWT
			// 
			this->lblAWT->AutoSize = true;
			this->lblAWT->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblAWT->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAWT->ForeColor = System::Drawing::Color::White;
			this->lblAWT->Location = System::Drawing::Point(666, 283);
			this->lblAWT->Name = L"lblAWT";
			this->lblAWT->Size = System::Drawing::Size(149, 18);
			this->lblAWT->TabIndex = 16;
			this->lblAWT->Text = L"Ave. Waiting Time";
			// 
			// txtboxATT
			// 
			this->txtboxATT->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtboxATT->Location = System::Drawing::Point(378, 305);
			this->txtboxATT->Name = L"txtboxATT";
			this->txtboxATT->Size = System::Drawing::Size(181, 23);
			this->txtboxATT->TabIndex = 17;
			this->txtboxATT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtboxAWT
			// 
			this->txtboxAWT->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtboxAWT->Location = System::Drawing::Point(650, 305);
			this->txtboxAWT->Name = L"txtboxAWT";
			this->txtboxAWT->Size = System::Drawing::Size(181, 23);
			this->txtboxAWT->TabIndex = 18;
			this->txtboxAWT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtboxCPU
			// 
			this->txtboxCPU->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtboxCPU->Location = System::Drawing::Point(916, 305);
			this->txtboxCPU->Name = L"txtboxCPU";
			this->txtboxCPU->Size = System::Drawing::Size(181, 23);
			this->txtboxCPU->TabIndex = 20;
			this->txtboxCPU->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lblCPU
			// 
			this->lblCPU->AutoSize = true;
			this->lblCPU->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblCPU->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCPU->ForeColor = System::Drawing::Color::White;
			this->lblCPU->Location = System::Drawing::Point(943, 283);
			this->lblCPU->Name = L"lblCPU";
			this->lblCPU->Size = System::Drawing::Size(125, 18);
			this->lblCPU->TabIndex = 19;
			this->lblCPU->Text = L"CPU Utilization";
			// 
			// groupBox2
			// 
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(343, 36);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(794, 319);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Output";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1164, 410);
			this->Controls->Add(this->txtboxCPU);
			this->Controls->Add(this->lblCPU);
			this->Controls->Add(this->txtboxAWT);
			this->Controls->Add(this->txtboxATT);
			this->Controls->Add(this->lblAWT);
			this->Controls->Add(this->lblATT);
			this->Controls->Add(this->txtboxPriority);
			this->Controls->Add(this->lblPriority);
			this->Controls->Add(this->lstTitle);
			this->Controls->Add(this->lstboxDisplay);
			this->Controls->Add(this->btnSubmit);
			this->Controls->Add(this->txtboxBurst);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtboxArrival);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cbbAlgo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->ForeColor = System::Drawing::Color::Cornsilk;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

		String^ stdDetails = "{0,15}{1,22}{2,22}{3, 25}{4, 25}{5, 25}{6, 25}";
		String^ stdDetailsNpp = "{0,15}{1,22}{2,22}{3, 18}{4, 25}{5, 25}{6, 25}";
		String^ stdDisplay = "{0,0}{1,0}{2,0}{3,0}{4, 0}{5, 0}{6, 0}{7,0}{8,0}{9,0}{10,0}{11,0}{12,0}{13, 0}";
		String^ ave = "{0, 0}{1, 5}{2, 3}";

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		lstboxDisplay->Hide();
		txtboxATT->Hide();
		txtboxAWT->Hide();
		txtboxCPU->Hide();
		lblATT->Hide();
		lblAWT->Hide();
		lblCPU->Hide();
	}

	private: System::Void cbbAlgo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		lstTitle->Text = cbbAlgo->Text;
		txtboxPriority->Hide();
		lblPriority->Hide();
		
		this->btnSubmit->Location = System::Drawing::Point(95, 256);

		if (cbbAlgo->Text == "NPP (Non-Preemptive Priority)") {
			txtboxPriority->Show();
			lblPriority->Show();
			btnSubmit->Location = System::Drawing::Point(95, 313);
		}
	}

	private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
		lstboxDisplay->Items->Clear();
		lstboxDisplay->Show();
		if (cbbAlgo->Text == "FCFS (First Come First Serve)") {
			txtboxATT->Show();
			txtboxAWT->Show();
			txtboxCPU->Show();
			lblATT->Show();
			lblAWT->Show();
			lblCPU->Show();
			fcfs(txtboxArrival->Text, txtboxBurst->Text);
		} else if (cbbAlgo->Text == "SRTF (Shortest Remaining Time First)") {
			txtboxATT->Show();
			txtboxAWT->Show();
			txtboxCPU->Show();
			lblATT->Show();
			lblAWT->Show();
			lblCPU->Show();
			srtf(txtboxArrival->Text, txtboxBurst->Text);
		} else {
			lblATT->Show();
			lblAWT->Show();
			lblCPU->Show();
			txtboxATT->Show();
			txtboxAWT->Show();
			txtboxCPU->Show();
			npp(txtboxArrival->Text, txtboxBurst->Text, txtboxPriority->Text);
		}
		

	}

		   void fcfs(String^ txtArrive, String^ txtBurst) {
			   // Declare variables to store process information and various metrics
			   int numProcesses;
			   vector<Process> processes;
			   float avgTurnaroundTime, avgWaitingTime, avgResponseTime, cpuUtilization, throughput;
			   int totalTurnaroundTime = 0, totalWaitingTime = 0, totalResponseTime = 0, totalIdleTime = 0;
			   String^ tempBurstTime, ^ tempArrivalTime = "";

			   // Input handling for arrival times

			   tempArrivalTime = txtArrive;
			   string arrivalTimeStr = msclr::interop::marshal_as<std::string>(tempArrivalTime);
			   istringstream iss(arrivalTimeStr);

			   // Read arrival times and store them in the 'at' vector
			   vector<int> at;
			   for (int number; iss >> number || (iss.eof() && at.empty());) {
				   at.push_back(number);

				   // Check for a comma and consume it if not at the end of the input
				   if (iss >> std::ws && iss.peek() == ',') {
					   iss.ignore();
				   }
			   }

			   // Input handling for burst times
			   tempBurstTime = txtBurst;
			   std::string burstTimeStr = msclr::interop::marshal_as<std::string>(tempBurstTime);
			   istringstream isss(burstTimeStr);

			   // Read burst times and store them in the 'bt' vector
			   vector<int> bt;
			   for (int number; isss >> number || (isss.eof() && bt.empty());) {
				   bt.push_back(number);

				   // Check for a comma and consume it if not at the end of the input
				   if (isss >> std::ws && isss.peek() == ',') {
					   isss.ignore();
				   }
			   }

			   if (at.size() != bt.size()) {
				   MessageBox::Show("Invalid Input.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   // Validation to check if the number of bt and at is the same, if not exit
			   /*if (at.size() != bt.size()) {
				   MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			   }*/

			   // Initialize the number of processes
			   numProcesses = at.size();

			   // Store the values to the struct process
			   for (int i = 0; i < numProcesses; i++) {
				   Process process;
				   process.id = i + 1;  // Assign a unique id
				   process.arrivalTime = at[i];
				   process.burstTime = bt[i];
				   processes.push_back(process);
			   }

			   // Sort processes based on arrival time
			   sort(processes.begin(), processes.end(), compareArrival);
			   // Calculate various metrics for each process
			   for (int i = 0; i < numProcesses; i++) {
				   processes[i].startTime = (i == 0) ? processes[i].arrivalTime : max(processes[i - 1].completionTime, processes[i].arrivalTime);
				   processes[i].completionTime = processes[i].startTime + processes[i].burstTime;
				   processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
				   processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
				   processes[i].responseTime = processes[i].startTime - processes[i].arrivalTime;

				   // Update cumulative metrics
				   totalTurnaroundTime += processes[i].turnaroundTime;
				   totalWaitingTime += processes[i].waitingTime;
				   totalResponseTime += processes[i].responseTime;
				   totalIdleTime += (i == 0) ? processes[i].arrivalTime : (processes[i].startTime - processes[i - 1].completionTime);
			   }

			   // Calculate average metrics
			   avgTurnaroundTime = static_cast<float>(totalTurnaroundTime) / numProcesses;
			   avgWaitingTime = static_cast<float>(totalWaitingTime) / numProcesses;
			   avgResponseTime = static_cast<float>(totalResponseTime) / numProcesses;
			   cpuUtilization = ((processes[numProcesses - 1].completionTime - totalIdleTime) / static_cast<float>(processes[numProcesses - 1].completionTime)) * 100;
			   throughput = static_cast<float>(numProcesses) / (processes[numProcesses - 1].completionTime - processes[0].arrivalTime);

			   // Sort processes based on ID for output display
			   sort(processes.begin(), processes.end(), compareID);

			   // Display process information in tabular format
			   lstboxDisplay->Items->Clear();
			   lstboxDisplay->Items->Add(" ");
			   lstboxDisplay->Items->Add(String::Format(stdDetails, "PID", "Arrival Time", "Burst Time", "Completion Time", "Turnaround Time", "Waiting Time", "Priority"));
			   lstboxDisplay->Items->Add(" ");

			   for (const Process& p : processes) {
				   lstboxDisplay->Items->Add(String::Format(stdDisplay, "               ", p.id, "\t                    ", p.arrivalTime, "\t              ", p.burstTime, "\t\t          ", p.completionTime, "\t\t               ", p.turnaroundTime, "\t\t                    ", p.waitingTime, "\t\t", " "));
			   }

			   txtboxATT->Text = avgTurnaroundTime.ToString("F2");
			   txtboxAWT->Text = avgWaitingTime.ToString("F2");
			   txtboxCPU->Text = cpuUtilization.ToString("F2") + "%";
			   
		   }
		   void srtf(String^ txtArrive, String^ txtBurst) {
			   int numProcesses;
			   vector<Process> processes;
			   float avgTurnaroundTime, avgWaitingTime, cpuUtilization;
			   int totalTurnaroundTime = 0, totalWaitingTime = 0, totalIdleTime = 0;
			   String^ tempBursttime, ^tempArrivalTime;

			   // Set output precision to two decimal places
			   cout << setprecision(2) << fixed;

			   // Input handling for arrival times
			   tempArrivalTime = txtArrive;
			   string arrivalTimeStr = msclr::interop::marshal_as<std::string>(tempArrivalTime);
			   istringstream iss(arrivalTimeStr);


			   // Read arrival times and store them in the 'at' vector
			   vector<int> at;
			   for (int number; iss >> number || (iss.eof() && at.empty());) {
				   at.push_back(number);

				   // Check for a comma and consume it if not at the end of the input
				   if (iss >> std::ws && iss.peek() == ',') {
					   iss.ignore();
				   }
			   }

			   // Input handling for burst times
			   tempBursttime = txtBurst;
			   string burstTimeStr = msclr::interop::marshal_as<std::string>(tempBursttime);
			   istringstream isss(burstTimeStr);

			   // Read burst times and store them in the 'bt' vector
			   vector<int> bt;
			   for (int number; isss >> number || (isss.eof() && bt.empty());) {
				   bt.push_back(number);

				   // Check for a comma and consume it if not at the end of the input
				   if (isss >> std::ws && isss.peek() == ',') {
					   isss.ignore();
				   }
			   }

			   // Validation to check if the number of bt and at is the same, if not exit
			   if (at.size() != bt.size()) {
				   MessageBox::Show("Invalid Input.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   // Initialize the number of processes
			   numProcesses = at.size();

			   // Create processes using the input arrival times and burst times
			   processes.resize(numProcesses);

			   for (int i = 0; i < numProcesses; ++i) {
				   processes[i].id = i + 1;
				   processes[i].arrivalTime = at[i];
				   processes[i].burstTime = bt[i];
				   processes[i].remainingTime = processes[i].burstTime;
			   }

			   // Sort processes by arrival time
			   sort(processes.begin(), processes.end(), sortByArrival);

			   int currentTime = 0;
			   int completedProcesses = 0;
			   vector<int> ganttChart;

			   while (completedProcesses < numProcesses) {
				   int shortestRemainingTime = INT_MAX;
				   int selectedProcess = -1;

				   for (int i = 0; i < numProcesses; ++i) {
					   if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0 &&
						   processes[i].remainingTime < shortestRemainingTime) {
						   shortestRemainingTime = processes[i].remainingTime;
						   selectedProcess = i;
					   }
				   }

				   if (selectedProcess == -1) {
					   currentTime++;
				   }
				   else {
					   if (ganttChart.empty() || ganttChart.back() != processes[selectedProcess].id) {
						   ganttChart.push_back(processes[selectedProcess].id);
					   }

					   processes[selectedProcess].remainingTime--;
					   currentTime++;

					   if (processes[selectedProcess].remainingTime == 0) {
						   processes[selectedProcess].completionTime = currentTime;
						   processes[selectedProcess].turnaroundTime = processes[selectedProcess].completionTime - processes[selectedProcess].arrivalTime;
						   processes[selectedProcess].waitingTime = processes[selectedProcess].turnaroundTime - processes[selectedProcess].burstTime;

						   totalTurnaroundTime += processes[selectedProcess].turnaroundTime;
						   totalWaitingTime += processes[selectedProcess].waitingTime;

						   completedProcesses++;
					   }
				   }
			   }

			   // Calculate averages
			   avgTurnaroundTime = static_cast<float>(totalTurnaroundTime) / numProcesses;
			   avgWaitingTime = static_cast<float>(totalWaitingTime) / numProcesses;
			   cpuUtilization = (static_cast<float>(currentTime - totalIdleTime) / currentTime) * 100;

			   // Display process information in tabular format
			   lstboxDisplay->Items->Clear();
			   lstboxDisplay->Items->Add(" ");
			   lstboxDisplay->Items->Add(String::Format(stdDetails, "PID", "Arrival Time", "Burst Time", "Completion Time", "Turnaround Time", "Waiting Time", "Priority"));
			   lstboxDisplay->Items->Add(" ");

			   for (const Process& p : processes) {
				   lstboxDisplay->Items->Add(String::Format(stdDisplay, "               ", p.id, "\t                    ", p.arrivalTime, "\t              ", p.burstTime, "\t\t          ", p.completionTime, "\t\t               ", p.turnaroundTime, "\t\t                    ", p.waitingTime, "\t\t", " "));
			   }

			   txtboxATT->Text = avgTurnaroundTime.ToString("F2");
			   txtboxAWT->Text = avgWaitingTime.ToString("F2");
			   txtboxCPU->Text = cpuUtilization.ToString("F2") + "%";
		   }
		   void npp(String^ txtArrive, String^ txtBurst, String^ txtPriority) {
			   int numProcesses;
			   vector<Process> processes;
			   float avgTurnaroundTime;
			   float avgWaitingTime;
			   float avgResponseTime;
			   float cpuUtilization;
			   int totalTurnaroundTime = 0;
			   int totalWaitingTime = 0;
			   int totalResponseTime = 0;
			   int totalIdleTime = 0;
			   float throughput;	
			   vector<int> isCompleted;
			   String ^tempBurstTime, ^tempArrivalTime, ^tempPriority;

			   // User input for arrival times
			   tempArrivalTime = txtArrive;
			   string arrivalTimeStr = msclr::interop::marshal_as<std::string>(tempArrivalTime);
			   istringstream iss(arrivalTimeStr);

			   vector<int> arrivalTime;
			   vector<int> burstTime;
			   vector<int> priority;

			   // Read integers separated by commas using a for loop
			   char comma;  // Variable to store the comma
			   for (int number; iss >> number || (iss.eof() && arrivalTime.empty());) {
				   arrivalTime.push_back(number);

				   // Check for a comma and consume it if not at the end of the input
				   if (iss >> std::ws && iss.peek() == ',') {
					   iss.ignore();
				   }
			   }

			   // User input for burst times
			   tempBurstTime = txtBurst;
			   string burstTimeStr = msclr::interop::marshal_as<std::string>(tempBurstTime);
			   istringstream isss(burstTimeStr);

			   // Read integers separated by commas using a for loop
			   for (int number; isss >> number || (isss.eof() && burstTime.empty());) {
				   burstTime.push_back(number);

				   // Check for a comma and consume it if not at the end of the input
				   if (isss >> std::ws && isss.peek() == ',') {
					   isss.ignore();
				   }
			   }

			   // User input for priorities
			   tempPriority = txtPriority;
			   string priorityStr = msclr::interop::marshal_as<std::string>(tempPriority);
			   istringstream issss(priorityStr);

			   // Read integers separated by commas using a for loop
			   for (int number; issss >> number || (issss.eof() && priority.empty());) {
				   priority.push_back(number);

				   // Check for a comma and consume it if not at the end of the input
				   if (issss >> std::ws && issss.peek() == ',') {
					   issss.ignore();
				   }
			   }
			  
			   if (arrivalTime.size() != burstTime.size() || arrivalTime.size() != priority.size() || burstTime.size() != priority.size()) {
				   MessageBox::Show("Invalid Input.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   // Initialize the number of processes
			   numProcesses = arrivalTime.size();

			   // Store the values to the struct process
			   for (int i = 0; i < numProcesses; i++) {
				   Process process;
				   process.id = i + 1;  // Assign a unique id
				   process.arrivalTime = arrivalTime[i];
				   process.burstTime = burstTime[i];
				   process.priority = priority[i];
				   processes.push_back(process);
			   }

			   isCompleted.resize(numProcesses, 0);  // Initialize isCompleted vector

			   int currentTime = 0;
			   int completed = 0;
			   int prev = 0;

			   // Schedule processes using Priority Scheduling
			   while (completed != numProcesses) {
				   int idx = -1;
				   int mx = 1000000000; // set mx to a high value

				   // Find the process with the highest priority that has arrived
				   for (int i = 0; i < numProcesses; i++) {
					   if (processes[i].arrivalTime <= currentTime && isCompleted[i] == 0) {
						   if (processes[i].priority < mx) {
							   mx = processes[i].priority;
							   idx = i;
						   }
						   if (processes[i].priority == mx) {
							   if (processes[i].arrivalTime < processes[idx].arrivalTime) {
								   mx = processes[i].priority;
								   idx = i;
							   }
						   }
					   }
				   }

				   // Execute the selected process
				   if (idx != -1) {
					   processes[idx].startTime = currentTime;
					   processes[idx].completionTime = processes[idx].startTime + processes[idx].burstTime;
					   processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
					   processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
					   processes[idx].responseTime = processes[idx].startTime - processes[idx].arrivalTime;

					   totalTurnaroundTime += processes[idx].turnaroundTime;
					   totalWaitingTime += processes[idx].waitingTime;
					   totalResponseTime += processes[idx].responseTime;
					   totalIdleTime += processes[idx].startTime - prev;

					   isCompleted[idx] = 1;
					   completed++;
					   currentTime = processes[idx].completionTime;
					   prev = currentTime;
				   }
				   else {
					   currentTime++;
				   }
			   }

			   // Calculate additional metrics
			   int minArrivalTime = 10000000;
			   int maxCompletionTime = -1;

			   for (int i = 0; i < numProcesses; i++) {
				   minArrivalTime = min(minArrivalTime, processes[i].arrivalTime);
				   maxCompletionTime = max(maxCompletionTime, processes[i].completionTime);
			   }

			   avgTurnaroundTime = static_cast<float>(totalTurnaroundTime) / numProcesses;
			   avgWaitingTime = static_cast<float>(totalWaitingTime) / numProcesses;
			   avgResponseTime = static_cast<float>(totalResponseTime) / numProcesses;
			   cpuUtilization = ((maxCompletionTime - totalIdleTime) / static_cast<float>(maxCompletionTime)) * 100;
			   throughput = static_cast<float>(numProcesses) / (maxCompletionTime - minArrivalTime);

			   // Display process information in tabular format
			   lstboxDisplay->Items->Clear();
			   lstboxDisplay->Items->Add(" ");
			   lstboxDisplay->Items->Add(String::Format(stdDetails, "PID", "Arrival Time", "Burst Time", "Completion Time", "Turnaround Time", "Waiting Time", "Priority"));			   lstboxDisplay->Items->Add(" ");

			   for (const Process& p : processes) {
				   lstboxDisplay->Items->Add(String::Format(stdDisplay, "               ", p.id, "\t                    ", p.arrivalTime, "\t              ", p.burstTime, "\t\t          ", p.completionTime, "\t\t               ", p.turnaroundTime, "\t\t                    ", p.waitingTime, "\t\t", " "));
			   }

			   txtboxATT->Text = avgTurnaroundTime.ToString("F2");
			   txtboxAWT->Text = avgWaitingTime.ToString("F2");
			   txtboxCPU->Text = cpuUtilization.ToString("F2") + "%";
		   }

private: System::Void lstboxDisplay_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}