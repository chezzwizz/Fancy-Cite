#pragma once

#using <mscorlib.dll>

namespace FancyCite {
  using namespace System;
  using namespace System::Globalization;
  using namespace System::Collections::Generic;

  public enum class ResourceName {
    txtLblAuthor, txtLblTitle, txtLblVolume, txtLblEdition, txtLblCity,
    txtLblState, txtLblPublisher, cbTxtOnline, citeIEEETxtOnlineAvailable,
    citeIEEETxtAccessed, comboItemIEEETxt, txtLblComboFormat,
    citeIEEEKey, citeIEEEOnlineKey
  };

  typedef Dictionary<ResourceName, String^> LanguageDictionary;

  ref class Resources {
  private:
    static CultureInfo^ m_locale = nullptr;
    static LanguageDictionary^ m_enStrings = nullptr;
    static LanguageDictionary^ m_frStrings = nullptr; 
    static LanguageDictionary^ m_stringDictionary = nullptr;

  public:
    static property CultureInfo^ Culture {
      CultureInfo^ get() {
        return m_locale;
      }

      void set(CultureInfo^ locale) {

        m_locale = locale;

        switch(locale->LCID) {

            case(0x409): // en-US
              if(!m_enStrings) InitEnStrings();
              m_stringDictionary = m_enStrings;
              break;

            case(0x40C): // fr-FR
              if(!m_frStrings) InitFrStrings();
              m_stringDictionary = m_frStrings;
              break;

            default:
              m_stringDictionary = m_enStrings;
              break;

        }
      }

    }

    static property LanguageDictionary^ Strings {
      LanguageDictionary^ get() {
        if(!m_stringDictionary) {
          InitStaticResources();
        }

        return m_stringDictionary;
      }
    }

    static void InitEnStrings() {
      m_enStrings = gcnew LanguageDictionary();
      m_enStrings->Add(ResourceName::txtLblAuthor, "Author");
      m_enStrings->Add(ResourceName::txtLblTitle, "Title");
      m_enStrings->Add(ResourceName::txtLblVolume, "Volume");
      m_enStrings->Add(ResourceName::txtLblEdition, "Edition");
      m_enStrings->Add(ResourceName::txtLblCity, "City");
      m_enStrings->Add(ResourceName::txtLblState, "State");
      m_enStrings->Add(ResourceName::txtLblPublisher, "Publisher");
      m_enStrings->Add(ResourceName::cbTxtOnline, "Online Source");
      m_enStrings->Add(ResourceName::citeIEEETxtOnlineAvailable, "[online] Available: ");
      m_enStrings->Add(ResourceName::citeIEEETxtAccessed, "Accessed: ");
      m_enStrings->Add(ResourceName::comboItemIEEETxt, "IEEE");
      m_enStrings->Add(ResourceName::txtLblComboFormat, "Select reference format:");
      m_enStrings->Add(ResourceName::citeIEEEKey, "Author, Title, Volume, Edition. City, State, Publisher, Year");
      m_enStrings->Add(ResourceName::citeIEEEOnlineKey, "Author, Title, Volume, Edition. City, State, Country, Publisher, Year. [online] Available: URL. Accessed: Month, Day, Year");
    }

    static void InitFrStrings() {
      m_frStrings = gcnew LanguageDictionary();
      m_frStrings->Add(ResourceName::txtLblAuthor, "Auteur");
      
    }

    static void InitStaticResources() {
      Culture = CultureInfo::CurrentCulture;
    }
  };
};
