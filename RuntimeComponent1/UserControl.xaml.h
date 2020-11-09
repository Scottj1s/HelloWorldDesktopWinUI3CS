#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "UserControl.g.h"

namespace winrt::RuntimeComponent1::implementation
{
    struct UserControl : UserControlT<UserControl>
    {
        UserControl();

        int32_t _myProperty{};
        int32_t MyProperty();
        void MyProperty(int32_t value);

        hstring _title{L"some text"};
        hstring Title();
        void Title(hstring const& value);

        Windows::Foundation::Uri _Source{L"http://aka.ms/cswinrt"};
        Windows::Foundation::Uri Source();
        void Source(Windows::Foundation::Uri const& value);
        static Microsoft::UI::Xaml::DependencyProperty SourceProperty();
        static Microsoft::UI::Xaml::DependencyProperty m_SourceProperty;
        static void OnSourceChanged(Microsoft::UI::Xaml::DependencyObject const&, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        hstring _Text{ L"hello" };
        hstring Text();
        void Text(hstring const& value);
        static Microsoft::UI::Xaml::DependencyProperty TextProperty();
        static Microsoft::UI::Xaml::DependencyProperty m_TextProperty;
        static void OnTextChanged(Microsoft::UI::Xaml::DependencyObject const&, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> _propertyChanged{};
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

        Microsoft::UI::Xaml::Data::ICustomProperty _titleProperty{};
        Microsoft::UI::Xaml::Data::ICustomProperty _linkProperty{};
        Microsoft::UI::Xaml::Data::ICustomProperty GetCustomProperty(hstring const& name);
        Microsoft::UI::Xaml::Data::ICustomProperty GetIndexedProperty(hstring const& name, Windows::UI::Xaml::Interop::TypeName const& type);
        hstring GetStringRepresentation();
        Windows::UI::Xaml::Interop::TypeName Type();

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::RuntimeComponent1::factory_implementation
{
    struct UserControl : UserControlT<UserControl, implementation::UserControl>
    {
    };
}
