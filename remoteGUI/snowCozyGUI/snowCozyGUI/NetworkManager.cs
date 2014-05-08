using System;
using System.Net;
using System.Net.Sockets;
using System.Windows.Forms;
using System.Text;

namespace snowCozyGUI
{
    public class NetworkManager
    {
        private Socket client;
        private byte[] buffer;
        private int bufferSize;
        public string hostAddress;
        public bool valid;

        public NetworkManager()
        {
            hostAddress = "";
            buffer = null;
            valid = false;
        }

        private void Set()
        {
            client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            client.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReuseAddress, 1);
            client.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.NoDelay, true);

            client.Blocking = true;

            buffer = new byte[bufferSize];
        }

        public void Send(String str)
        {
            if (isAlive())
            {
                try
                {
                    client.Send(Encoding.Default.GetBytes(str + "\r\n"));
                }
                catch
                {
                    //send failed -> disconnected
                }
            }
        }

        public bool ConnectIP(String ip, int port, int buffSize)
        {
            bufferSize = buffSize;
            Set();
            EndPoint host = new IPEndPoint(IPAddress.Parse(ip), port);

            bool success = false;

            try
            {
                client.Connect(host);
                hostAddress = ip + ":" + port.ToString();
            }
            catch
            {
                MessageBox.Show("Unable to connect to Einar!");
            }

            if (isAlive())
            {
                success = true;
            }

            //the status of the connection
            valid = success;
            return success;
        }

        public void Disconnect()
        {
            valid = false;
            if (client != null)
            {
                client.Close();
                client = null;
            }
        }

        private bool isAlive()
        {
            return client != null && client.Connected;
        }

    }
}
