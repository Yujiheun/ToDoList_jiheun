#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainFrame* mainFrame = new MainFrame("지흔이의 투두리스트");
    mainFrame->SetClientSize(800, 600);
    mainFrame->Center();
    mainFrame->Show();

    return true;
}