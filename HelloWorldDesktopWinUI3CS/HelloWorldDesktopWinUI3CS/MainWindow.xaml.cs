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

// The Blank Window item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace WinRT
{
    public class WeakReference<T> : global::System.WeakReference<T>
    { }
}


namespace HelloWorldDesktopWinUI3CS
{
    /// <summary>
    /// An empty window that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainWindow : Window
    {
        public MainWindow()
        {
            this.InitializeComponent();

            //RuntimeComponent1.UserControl userControl = new RuntimeComponent1.UserControl();

            //FAIL spanel.Children.Add(userControl);
        }

        private async void myButton_Click(object sender, RoutedEventArgs e)
        {
            myButton.Content = "Clicked";

            //IntPtr hwnd = PInvoke.User32.GetActiveWindow();
            IntPtr hwnd = (App.Current as App).MainWindowWindowHandle;
            PInvoke.User32.ShowWindow(hwnd, PInvoke.User32.WindowShowStyle.SW_MAXIMIZE);


            //var description = new System.Text.StringBuilder();
            //var process = System.Diagnostics.Process.GetCurrentProcess();
            //foreach (System.Diagnostics.ProcessModule module in process.Modules)
            //{
            //    description.AppendLine(module.FileName);
            //}

            //cdTextBlock.Text = description.ToString();
            //contentDialog.XamlRoot = myButton.XamlRoot;
            //await contentDialog.ShowAsync();

        }


    }
}
