#using <mscorlib.dll>
#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

#include "Resources.h"

namespace FancyCite {
  using namespace System;
  using namespace System::Windows::Forms;
  using namespace System::Drawing;

  public ref class MainForm : public Form {
  public:

    MainForm(void)
    {
      m_labels = gcnew ControlCollection();
      m_textBoxs = gcnew ControlCollection();

      m_labels->Add(Ctrl::Author, gcnew Label());
      m_labels[Ctrl::Author]->Text = Resources::Strings[ResourceName::txtLblAuthor];
      m_labels[Ctrl::Author]->Location = Point(10, 10);

      m_textBoxs->Add(Ctrl::Author, gcnew TextBox());
      m_textBoxs[Ctrl::Author]->Location = Point(OffsetByWidth(m_labels[Ctrl::Author]), 
                                           m_labels[Ctrl::Author]->Location.Y);

      m_labels->Add(Ctrl::Title, gcnew Label());
      m_labels[Ctrl::Title]->Text = Resources::Strings[ResourceName::txtLblTitle];
      m_labels[Ctrl::Title]->Location = Point(m_labels[Ctrl::Author]->Location.X,
                                              OffsetByHeight(m_labels[Ctrl::Author]));

      m_textBoxs->Add(Ctrl::Title, gcnew TextBox());
      m_textBoxs[Ctrl::Title]->Location = Point(OffsetByWidth(m_labels[Ctrl::Title]), 
                                           m_labels[Ctrl::Title]->Location.Y);

      m_btnExit = gcnew Button();
      m_btnExit->Text = "Exit!";
      m_btnExit->Click += gcnew EventHandler(this, &MainForm::ExitButton_Click);
      m_btnExit->Location = Point(Size.Width - m_btnExit->Size.Width - 10,
                                  Size.Height - m_btnExit->Size.Height - 10);

      for (int i = 0; i < (int)Ctrl::Volume; ++i) {
        Console::WriteLine(i);
        Controls->Add(m_labels[(Ctrl)i]);
        Controls->Add(m_textBoxs[(Ctrl)i]);
      }

      Controls->Add(m_btnExit);

      Text = "Managed C++ Windows Forms Application";
    }

  private:
    enum class Ctrl {
      Author, Title, Volume, Edition, SZ
    };

    typedef Dictionary<Ctrl, Control^> ControlCollection;

    ControlCollection^ m_labels;
    ControlCollection^ m_textBoxs;
    ControlCollection^ m_buttons;

    Button^ m_btnExit;

    inline int OffsetByWidth(Control^ ctrl, int extra) {
      return (ctrl->Location.X + ctrl->Size.Width + extra);
    }

    inline int OffsetByWidth(Control^ ctrl) {
      return (ctrl->Location.X + ctrl->Size.Width);
    }

    inline int OffsetByHeight(Control^ ctrl, int extra) {
      return (ctrl->Location.Y + ctrl->Size.Height + extra);
    }

    inline int OffsetByHeight(Control^ ctrl) {
      return (ctrl->Location.Y + ctrl->Size.Height);
    }

  private:
    void ExitButton_Click(Object^ sender, EventArgs^ e) {
      Application::Exit();
    }

  };
};

int main()
{
  System::Windows::Forms::Application::Run(gcnew FancyCite::MainForm());
  return 0;
}
