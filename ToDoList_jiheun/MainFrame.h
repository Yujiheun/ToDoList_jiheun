#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

private:
	void CreateControls(); //��Ʈ�ѷ��� �����ϴ� �޼ҵ�
	void BindEventHandlers(); //��Ʈ�ѷ��� �̺�Ʈ �ڵ鷯�� Bind()�ϴ� �޼ҵ�
	void AddSavedTasks(); //������ �ҷ����� �޼ҵ�

	void OnAddButtonClicked(wxCommandEvent& evt); //'�߰�'��ư�� ������ �߻��ϴ� �̺�Ʈ �ڵ鷯
	void OnInputEnter(wxCommandEvent& evt); // EnterŰ�� ������ �߻��ϴ� �̺�Ʈ �ڵ鷯
	void OnListKeyDown(wxKeyEvent& evt); //Ű�� ������ �߻��ϴ� �̺�Ʈ �ڵ鷯
	void OnClearButtonClicked(wxCommandEvent& evt); ////'�����'��ư�� ������ �߻��ϴ� �̺�Ʈ �ڵ鷯
	void OnWindowClosed(wxCloseEvent& evt); //â Ȥ�� �������� ������ �߻��ϴ� �̺�Ʈ �ڵ鷯

	void AddTaskFromInput();
	void DeleteSelectedTask();
	void MoveSelectedTask(int offset);
	void SwapTask(int i, int j);

	wxPanel* panel;
	wxStaticText* headlineText;
	wxTextCtrl* inputField;
	wxButton* addButton;
	wxCheckListBox* checkListBox;
	wxButton* clearButton;
};