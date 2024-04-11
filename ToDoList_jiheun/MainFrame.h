#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

private:
	void CreateControls(); //컨트롤러를 정의하는 메소드
	void BindEventHandlers(); //컨트롤러와 이벤트 핸들러를 Bind()하는 메소드
	void AddSavedTasks(); //파일을 불러오는 메소드

	void OnAddButtonClicked(wxCommandEvent& evt); //'추가'버튼을 누르면 발생하는 이벤트 핸들러
	void OnInputEnter(wxCommandEvent& evt); // Enter키를 누르면 발생하는 이벤트 핸들러
	void OnListKeyDown(wxKeyEvent& evt); //키를 누르면 발생하는 이벤트 핸들러
	void OnClearButtonClicked(wxCommandEvent& evt); ////'지우기'버튼을 누르면 발생하는 이벤트 핸들러
	void OnWindowClosed(wxCloseEvent& evt); //창 혹은 프레임이 닫히면 발생하는 이벤트 핸들러

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