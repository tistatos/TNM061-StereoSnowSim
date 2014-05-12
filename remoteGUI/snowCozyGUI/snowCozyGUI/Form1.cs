using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace snowCozyGUI
{
    struct clientData
    {
        public NetworkManager connection;
        public string ip;
        public Int32 port;
        public int bufferSize;
        public int choice; //0 for wind, 1 for vortex
    }

    public partial class Form1 : Form
    {
        private clientData mClient;

        public Form1()
        {
            InitializeComponent();
            init();
        }

        private void init()
        {
            mClient = new clientData();
            mClient.connection = new NetworkManager();
            mClient.port = 24250;
            mClient.bufferSize = 1024;
            //default ip
            mClient.ip = "127.0.0.1";

            componentVisability(false);

            //add ip and message to the gui
            this.statusMessage.Text = "Disconnected";
            this.ipTextBox.Text = mClient.ip;

        }

        private void exit()
        {
            disconnect();
            System.Environment.Exit(0);
        }

        private void connectButton_Click(object sender, EventArgs e)
        {
            if (!mClient.connection.valid)
            {
                //get the ip address string from the textbox
                mClient.ip = this.ipTextBox.Text;

                connect();
            }
            else
            {
                disconnect();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void connect()
        {
            //if connection is successfull
            if (mClient.connection.ConnectIP(mClient.ip, mClient.port, mClient.bufferSize))
            {
                componentVisability(true);
                this.connectButton.Text = "Disconnect";
                this.statusMessage.Text = "Connected to " + mClient.ip;
                //send defaults
                mClient.connection.Send("stats=0\r\ngraph=0\r\nwinX=0\r\nwinY=0\r\nwinZ=0\r\ngrav=0\r\nvorX=0\r\nvorY=0\r\nvorZ=0");
            }
            else
            {
                componentVisability(false);
                this.connectButton.Text = "Connect";
            }
        }

        private void disconnect()
        {
            componentVisability(false);
            this.connectButton.Text = "Connect";
            this.statusMessage.Text = "Disconnected";
            
            //set slider default value to 0
            this.xTrackBar.Value = 0;
            this.xForce.Text = "0";
            this.yTrackBar.Value = 0;
            this.yForce.Text = "0";
            this.zTrackBar.Value = 0;
            this.zForce.Text = "0";
            this.gravityTrackBar.Value = 0;
            this.gravityForce.Text = "0";

            if (mClient.connection != null)
            {
                //disconnect network manager
                mClient.connection.valid = false;
                mClient.connection.Disconnect();
            }
        }

        private void componentVisability(bool status)
        {
            //group box for properties should be grayed out when not connected
            this.propertiesGroupBox.Enabled = status;
        }

        private void xTrackBar_Scroll(object sender, EventArgs e)
        {
            TrackBar tBar = (TrackBar)sender;
            this.xForce.Text = tBar.Value.ToString();

            if (mClient.connection.valid)
            {
                System.Console.Write(mClient.choice);

                if (mClient.choice == 0)
                {
                    mClient.connection.Send("winX=" + tBar.Value.ToString());
                    System.Console.Write(tBar.Value.ToString());
                }
                else if (mClient.choice == 1)
                {
                    mClient.connection.Send("vorX=" + tBar.Value.ToString());
                    System.Console.Write(tBar.Value.ToString());
                }
            }
        }

        private void yTrackBar_Scroll(object sender, EventArgs e)
        {
            TrackBar tBar = (TrackBar)sender;
            this.yForce.Text = tBar.Value.ToString();

            if (mClient.connection.valid)
            {
                if (mClient.choice == 0)
                {
                    mClient.connection.Send("winY=" + tBar.Value.ToString());
                    System.Console.Write(tBar.Value.ToString());
                }
                else if (mClient.choice == 1)
                {
                    mClient.connection.Send("vorY=" + tBar.Value.ToString());
                    System.Console.Write(tBar.Value.ToString());
                }
                //System.Console.Write(tYBar.Value.ToString());
            }
        }

        private void zTrackBar_Scroll(object sender, EventArgs e)
        {
            TrackBar tBar = (TrackBar)sender;
            this.zForce.Text = tBar.Value.ToString();

            if (mClient.connection.valid)
            {
                if (mClient.choice == 0)
                {
                    mClient.connection.Send("winY=" + tBar.Value.ToString());
                    System.Console.Write(tBar.Value.ToString());
                }
                else if (mClient.choice == 1)
                {
                    mClient.connection.Send("vorY=" + tBar.Value.ToString());
                    System.Console.Write(tBar.Value.ToString());
                }
            }
        }

        private void gravityTrackBar_Scroll(object sender, EventArgs e)
        {
            TrackBar gravBar = (TrackBar)sender;
            this.gravityForce.Text = gravBar.Value.ToString();
            
            if (mClient.connection.valid)
            {
                mClient.connection.Send("grav=" + gravBar.Value.ToString());
            }
        }

        private void windRadio_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rButt = (RadioButton)sender;

            if (rButt.Checked)
            {
                mClient.choice = 0;
                System.Console.Write(mClient.choice);
            }
        }

        private void vortexRadio_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rButt = (RadioButton)sender;

            if (rButt.Checked)
            {
                mClient.choice = 1;
                System.Console.Write(mClient.choice);
            }
        }
    }
}
