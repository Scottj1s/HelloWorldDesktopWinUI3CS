#include "pch.h"
#include "UserControl.xaml.h"
#if __has_include("UserControl.g.cpp")
#include "UserControl.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// todo: fix cppwinrt
//using namespace winrt::param;
#include "base_xaml_typename.h"

namespace winrt::RuntimeComponent1::implementation
{
    struct TextProperty : implements<TextProperty, Microsoft::UI::Xaml::Data::ICustomProperty>
    {
        UserControl& _control;
        TextProperty(UserControl& control) : _control(control) {}
        Windows::UI::Xaml::Interop::TypeName Type()
        {
            throw hresult_not_implemented();
        }
        hstring Name()
        {
            return L"Text";
        }
        Windows::Foundation::IInspectable GetValue(Windows::Foundation::IInspectable const& target) 
        {
            return winrt::box_value(_control.Text());
        }
        void SetValue(Windows::Foundation::IInspectable const& target, Windows::Foundation::IInspectable const& value)
        {
            _control.Text(winrt::unbox_value<hstring>(value));
        }
        Windows::Foundation::IInspectable GetIndexedValue(Windows::Foundation::IInspectable const& target, Windows::Foundation::IInspectable const& index)
        {
            throw hresult_not_implemented();
        }
        void SetIndexedValue(Windows::Foundation::IInspectable const& target, Windows::Foundation::IInspectable const& value, Windows::Foundation::IInspectable const& index)
        {
            throw hresult_not_implemented();
        }
        bool CanWrite()
        {
            return true;
        }
        bool CanRead()
        {
            return true;
        }
    };

    struct SourceProperty : implements<SourceProperty, Microsoft::UI::Xaml::Data::ICustomProperty>
    {
        UserControl& _control;
        SourceProperty(UserControl& control) : _control(control) {}
        Windows::UI::Xaml::Interop::TypeName Type()
        {
            throw hresult_not_implemented();
        }
        hstring Name()
        {
            return L"Source";
        }
        Windows::Foundation::IInspectable GetValue(Windows::Foundation::IInspectable const& target)
        {
            return _control.Source();
        }
        void SetValue(Windows::Foundation::IInspectable const& target, Windows::Foundation::IInspectable const& value)
        {
            _control.Source(value.as<Windows::Foundation::Uri>());
        }
        Windows::Foundation::IInspectable GetIndexedValue(Windows::Foundation::IInspectable const& target, Windows::Foundation::IInspectable const& index)
        {
            throw hresult_not_implemented();
        }
        void SetIndexedValue(Windows::Foundation::IInspectable const& target, Windows::Foundation::IInspectable const& value, Windows::Foundation::IInspectable const& index)
        {
            throw hresult_not_implemented();
        }
        bool CanWrite()
        {
            return true;
        }
        bool CanRead()
        {
            return true;
        }
    };
    UserControl::UserControl()
    {
        InitializeComponent();

        //_titleProperty = winrt::make<TitleProperty>(*this);
        //_linkProperty = winrt::make<LinkProperty>(*this);
    }

    int32_t UserControl::MyProperty()
    {
        return _myProperty;
    }
    void UserControl::MyProperty(int32_t  value )
    {
        _myProperty = value;
    }
    hstring UserControl::Title()
    {
        return _title;
    }
    void UserControl::Title(hstring const& value)
    {
        if (_title != value)
        {
            _title = value;
            _propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Title" });
        }
    }

    Microsoft::UI::Xaml::DependencyProperty UserControl::m_SourceProperty =
        Microsoft::UI::Xaml::DependencyProperty::Register(
            L"Source",
            winrt::xaml_typename<Windows::Foundation::Uri>(),
            winrt::xaml_typename<RuntimeComponent1::UserControl>(),
            Microsoft::UI::Xaml::PropertyMetadata{ Windows::Foundation::Uri(L"http://aka.ms/cswinrt"), Microsoft::UI::Xaml::PropertyChangedCallback{ &UserControl::OnSourceChanged } }
    );
    void UserControl::OnSourceChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& /* e */)
    {
        if (RuntimeComponent1::UserControl theControl{ d.try_as<RuntimeComponent1::UserControl>() })
        {
            RuntimeComponent1::implementation::UserControl* ptr{ winrt::get_self<RuntimeComponent1::implementation::UserControl>(theControl) };
        }
    }
    Windows::Foundation::Uri UserControl::Source()
    {
        return winrt::unbox_value<Windows::Foundation::Uri>(GetValue(m_SourceProperty));
        //return (Windows::Foundation::Uri)(GetValue(m_SourceProperty));
        //return _Source;
    }
    void UserControl::Source(Windows::Foundation::Uri const& value)
    {
        SetValue(m_SourceProperty, winrt::box_value(value));
        //SetValue(m_SourceProperty, value);
        //if (_Source != value)
        //{
        //    _Source = value;
        //    _propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Source" });
        //}
    }
    Microsoft::UI::Xaml::DependencyProperty UserControl::SourceProperty()
    {
        return m_SourceProperty;
    }

    Microsoft::UI::Xaml::DependencyProperty UserControl::m_TextProperty =
        Microsoft::UI::Xaml::DependencyProperty::Register(
            L"Text",
            winrt::xaml_typename<hstring>(),
            winrt::xaml_typename<RuntimeComponent1::UserControl>(),
            Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(L"hello"), Microsoft::UI::Xaml::PropertyChangedCallback{ &UserControl::OnTextChanged } }
    );
    void UserControl::OnTextChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& /* e */)
    {
        if (RuntimeComponent1::UserControl theControl{ d.try_as<RuntimeComponent1::UserControl>() })
        {
            RuntimeComponent1::implementation::UserControl* ptr{ winrt::get_self<RuntimeComponent1::implementation::UserControl>(theControl) };
        }
    }
    hstring UserControl::Text()
    {
        return winrt::unbox_value<hstring>(GetValue(m_TextProperty));
        //return (Windows::Foundation::Uri)(GetValue(m_TextProperty));
        //return _Text;
    }
    void UserControl::Text(hstring  const& value)
    {
        SetValue(m_TextProperty, winrt::box_value(value));
        //SetValue(m_TextProperty, value);
        //if (_Text != value)
        //{
        //    _Text = value;
        //    _propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Text" });
        //}
    }
    Microsoft::UI::Xaml::DependencyProperty UserControl::TextProperty()
    {
        return m_TextProperty;
    }

    winrt::event_token UserControl::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return _propertyChanged.add(handler);
    }
    void UserControl::PropertyChanged(winrt::event_token const& token) noexcept
    {
        _propertyChanged.remove(token);
    }

    Microsoft::UI::Xaml::Data::ICustomProperty UserControl::GetCustomProperty(hstring const& name)
    {
        if (name == L"Title")
        {
            return _titleProperty;
        }
        if (name == L"Link")
        {
            return _linkProperty;
        }
        throw hresult_not_implemented();
    }
    Microsoft::UI::Xaml::Data::ICustomProperty UserControl::GetIndexedProperty(hstring const& name, Windows::UI::Xaml::Interop::TypeName const& type)
    {
        throw hresult_not_implemented();
    }
    hstring UserControl::GetStringRepresentation()
    {
        throw hresult_not_implemented();
    }
    Windows::UI::Xaml::Interop::TypeName UserControl::Type()
    {
        return {L"RuntimeComponent1.UserControl, HelloWorldDesktopWinUI3CS, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null", Windows::UI::Xaml::Interop::TypeKind::Custom};
    }

    void UserControl::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
