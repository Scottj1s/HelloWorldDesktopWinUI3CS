using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.ApplicationModel;
using Windows.ApplicationModel.Activation;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Microsoft.UI.Threading;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using Microsoft.UI.Xaml.Shapes;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Threading.Tasks;

namespace HelloWorldDesktopWinUI3CS
{
    /// <summary>
    /// Provides application-specific behavior to supplement the default Application class.
    /// </summary>
    public partial class App : Application
    {
        /// <summary>
        /// Initializes the singleton application object.  This is the first line of authored code
        /// executed, and as such is the logical equivalent of main() or WinMain().
        /// </summary>
        public App()
        {
            this.InitializeComponent();
            this.Suspending += OnSuspending;

        }

        /// <summary>
        /// Invoked when the application is launched normally by the end user.  Other entry points
        /// will be used such as when the application is launched to open a specific file.
        /// </summary>
        /// <param name="args">Details about the launch request and process.</param>
        /// 

        IntPtr m_windowhandle;
        public IntPtr MainWindowWindowHandle { get { return m_windowhandle; } }
        protected override void OnLaunched(Microsoft.UI.Xaml.LaunchActivatedEventArgs args)
        {
            m_window = new MainWindow();
            SetMainWindowBorderless();
            m_window.Activate();

            m_windowhandle = PInvoke.User32.GetActiveWindow();
            //this.Dispatcher.RunAsync(() hWnd = GetActiveWindow())

        }

        /// <summary>
        /// Invoked when application execution is being suspended.  Application state is saved
        /// without knowing whether the application will be terminated or resumed with the contents
        /// of memory still intact.
        /// </summary>
        /// <param name="sender">The source of the suspend request.</param>
        /// <param name="e">Details about the suspend request.</param>
        private void OnSuspending(object sender, SuspendingEventArgs e)
        {
            // Save application state and stop any background activity
        }

        private Window m_window;


        public static IntPtr SetWindow(IntPtr hWnd, int nIndex, IntPtr dwNewLong)
        {
            return Environment.Is64BitProcess ?
                SetWindowLongPtr(hWnd, nIndex, dwNewLong) :
                SetWindowLong(hWnd, nIndex, dwNewLong);
        }

        [DllImport("user32.dll", SetLastError = true, EntryPoint = "SetWindowLong")]
        private static extern IntPtr SetWindowLong(IntPtr hWnd, int nIndex, IntPtr dwNewLong);

        [DllImport("user32.dll", SetLastError = true, EntryPoint = "SetWindowLongPtr")]
        private static extern IntPtr SetWindowLongPtr(IntPtr hWnd, int nIndex, IntPtr dwNewLong);

        //If you have WPF experience, this is similar to WindowStyle="None"
        public static void SetMainWindowBorderless()
        {
            const int GWL_STYLE = -16;

            //WS_VISIBLE | WS_POPUP
            var WS_VISIBLE_POPUP = new IntPtr(unchecked((int)0x90000000));

            using var process = Process.GetCurrentProcess();
            var success = WS_VISIBLE_POPUP != SetWindow(
                process.MainWindowHandle,
                GWL_STYLE,
                WS_VISIBLE_POPUP);

            //Helpful when your day goes south
            Debug.WriteLineIf(!success, new System.ComponentModel.Win32Exception(Marshal.GetLastWin32Error()).Message);
        }

    }
}
