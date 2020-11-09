using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using System.Diagnostics;
using System.Runtime.InteropServices;


namespace HelloWorldDesktopWinUI3CS
{
    public class UriToStringConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, String language)
        {
            return value.ToString();
        }

        public object ConvertBack(object value, Type targetType, object parameter, String language)
        {
            Uri newUri;
            string uriString = value as string;
            try
            {
                Uri.TryCreate(uriString, UriKind.RelativeOrAbsolute, out newUri);
                return newUri;
            }
            catch
            {
                return null;
            }
        }
    }

    public class StringToStringConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, String language)
        {
            return value.ToString();
        }

        public object ConvertBack(object value, Type targetType, object parameter, String language)
        {
            return value.ToString();
        }
    }

    /// <summary>
    /// An empty window that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainWindow : Window
    {
        public MainWindow()
        {
            this.InitializeComponent();

            RuntimeComponent1.UserControl userControl = new RuntimeComponent1.UserControl();

            Binding testBlockBinding = new Binding() { Path = new PropertyPath("Text") };
            TestBlock.DataContext = MyControl;
            TestBlock.SetBinding(TextBlock.TextProperty, testBlockBinding);

            Binding textBoxBinding = new Binding() { Path = new PropertyPath("Text"), Mode = BindingMode.TwoWay, Converter = new StringToStringConverter() };
            TestBox.DataContext = MyControl;
            TestBox.SetBinding(TextBox.TextProperty, textBoxBinding);

            Binding sourceBlockBinding = new Binding() { Path = new PropertyPath("Source"), Converter = new UriToStringConverter() };
            SourceBlock.DataContext = MyControl;
            SourceBlock.SetBinding(TextBlock.TextProperty, sourceBlockBinding);

            Binding sourceBoxBinding = new Binding() { Path = new PropertyPath("Source"), Mode=BindingMode.TwoWay, Converter=new UriToStringConverter() };
            SourceBox.DataContext = MyControl;
            SourceBox.SetBinding(TextBox.TextProperty, sourceBoxBinding);

        }
    }
}
