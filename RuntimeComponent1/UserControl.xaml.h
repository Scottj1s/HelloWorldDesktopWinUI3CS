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

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::RuntimeComponent1::factory_implementation
{
    struct UserControl : UserControlT<UserControl, implementation::UserControl>
    {
    };
}
