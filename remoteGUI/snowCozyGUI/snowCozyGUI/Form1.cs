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
        public string windX;
        public string windY;
        public string windZ;
        public string vortexXBeg;
        public string vortexYBeg;
        public string vortexZBeg;
        public int vortexX;
        public int vortexY;
        public int vortexZ;
        public string vortexXEnd;
        public string vortexYEnd;
        public string vortexZEnd;
        public string vortexRadius;
        public string vortexPosX;
        public string vortexPosZ;
        public string pause; //0 for go, 1 for pause
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

        private void connect()
        {
            //if connection is successfull
            if (mClient.connection.ConnectIP(mClient.ip, mClient.port, mClient.bufferSize))
            {
                //change button text and add message
                this.connectButton.Text = "Disconnect";
                this.statusMessage.Text = "Connected to " + mClient.ip;

                //make chosen boxes available
                this.fieldGroupBox.Enabled = true;
                this.programGroupBox.Enabled = true;
                this.fadeDistGroupBox.Enabled = true;
                this.partGroupBox.Enabled = true;

                mClient.windX = "0";
                mClient.windY = "0";
                mClient.windZ = "0";
                mClient.vortexXBeg = "0";
                mClient.vortexYBeg = "0";
                mClient.vortexZBeg = "0";
                mClient.vortexXEnd = "0";
                mClient.vortexYEnd = "0";
                mClient.vortexZEnd = "0";
                mClient.vortexX = 0;
                mClient.vortexY = 0;
                mClient.vortexZ = 0;
                mClient.vortexRadius = "1";
                mClient.vortexPosX = "0";
                mClient.vortexPosZ = "-1";
                mClient.pause = "0";

                //set default values
                this.radiusTextBox.Text = mClient.vortexRadius;
                this.posXTextBox.Text = mClient.vortexPosX;
                this.posZTextBox.Text = mClient.vortexPosZ;

                //send defaults
                mClient.connection.Send("stats=0\r\ngraph=0\r\nwinX=0\r\nwinY=0\r\nwinZ=0\r\ngrav=10\r\nvorX=0\r\nvorY=0\r\nvorZ=0\r\npaus=0\r\nradi=1\r\nfade=40\r\npart=40\r\ninfo=0");
            }
            else
            {
                this.connectButton.Text = "Connect";
            }
        }

        private void disconnect()
        {
            componentVisability(false);
            this.connectButton.Text = "Connect";
            this.statusMessage.Text = "Disconnected";
            this.pausButton.Text = "Pause";


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
            this.fieldGroupBox.Enabled = status;
            this.forceGroupBox.Enabled = status;
            this.gravityGroupBox.Enabled = status;
            this.propertiesGroupBox.Enabled = status;
            this.programGroupBox.Enabled = status;
            this.fadeDistGroupBox.Enabled = status;
            this.partGroupBox.Enabled = status;
            this.windRadio.Checked = status;
            this.vortexRadio.Checked = status;
            this.gravityButton.Checked = status;
            this.timer.Enabled = status;
        }

        private void xTrackBar_Scroll(object sender, EventArgs e)
        {
            TrackBar tBar = (TrackBar)sender;
            this.xForce.Text = tBar.Value.ToString();

            if (mClient.connection.valid)
            {
                if (mClient.choice == 0)
                {
                    mClient.windX = tBar.Value.ToString();
                    mClient.connection.Send("winX=" + mClient.windX);
                }
                else if (mClient.choice == 1)
                {
                    mClient.vortexXEnd = tBar.Value.ToString();
                    mClient.vortexX = Int32.Parse(mClient.vortexXBeg);
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
                    mClient.windY = tBar.Value.ToString();
                    mClient.connection.Send("winY=" + mClient.windY);
                }
                else if (mClient.choice == 1)
                {
                    mClient.vortexYEnd = tBar.Value.ToString();
                    mClient.vortexY = Int32.Parse(mClient.vortexYBeg);
                }
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
                    mClient.windZ = tBar.Value.ToString();
                    mClient.connection.Send("winZ=" + mClient.windZ);
                    //System.Console.Write(tBar.Value.ToString());
                }
                else if (mClient.choice == 1)
                {
                    mClient.vortexZEnd = tBar.Value.ToString();
                    mClient.vortexZ = Int32.Parse(mClient.vortexZBeg);
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

                this.xTrackBar.Value = Convert.ToInt32(mClient.windX);
                this.xForce.Text = mClient.windX;
                this.yTrackBar.Value = Convert.ToInt32(mClient.windY);
                this.yForce.Text = mClient.windY;
                this.zTrackBar.Value = Convert.ToInt32(mClient.windZ);
                this.zForce.Text = mClient.windZ;

                this.forceGroupBox.Enabled = true;
                this.gravityGroupBox.Enabled = false;

                this.statusMessage.Text = "change the value of wind";

               //System.Console.Write(mClient.choice);
            }
        }

        private void vortexRadio_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rButt = (RadioButton)sender;

            if (rButt.Checked)
            {
                mClient.choice = 1;
                this.timer.Enabled = true;

                this.xTrackBar.Value = Convert.ToInt32(mClient.vortexXEnd);
                this.xForce.Text = mClient.vortexXBeg;
                this.yTrackBar.Value = Convert.ToInt32(mClient.vortexYEnd);
                this.yForce.Text = mClient.vortexYBeg;
                this.zTrackBar.Value = Convert.ToInt32(mClient.vortexZEnd);
                this.zForce.Text = mClient.vortexZBeg;

                this.forceGroupBox.Enabled = true;
                this.propertiesGroupBox.Enabled = true;
                this.gravityGroupBox.Enabled = false;

                this.statusMessage.Text = "change the value of vortex";

                System.Console.Write(mClient.choice);
            }
        }

        private void gravityButton_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rButt = (RadioButton)sender;

            if (rButt.Checked)
            {
                this.forceGroupBox.Enabled = false;
                this.gravityGroupBox.Enabled = true;

                this.statusMessage.Text = "change the value of gravity";
            }
        }

        private void pausButton_Click(object sender, EventArgs e)
        {
            if (mClient.pause == "0")
            {
                mClient.pause = "1";
                this.pausButton.Text = "Start";
                this.statusMessage.Text = "Program is paused";

                mClient.connection.Send("paus=" + mClient.pause);
            }
            else
            {
                mClient.pause = "0";
                this.pausButton.Text = "Pause";
                this.statusMessage.Text = "Program is unpaused";

                mClient.connection.Send("paus=" + mClient.pause);
            }

        }

        private void radiusTextBox_TextChanged(object sender, EventArgs e)
        {
            mClient.vortexRadius = radiusTextBox.Text;
            mClient.connection.Send("radi=" + mClient.vortexRadius);

            //System.Console.Write(mClient.vortexRadius);
        }

        private void posXTextBox_TextChanged(object sender, EventArgs e)
        {
            mClient.vortexPosX = posXTextBox.Text;
            mClient.connection.Send("posX=" + mClient.vortexPosX);
        }

        private void posZTextBox_TextChanged(object sender, EventArgs e)
        {
            mClient.vortexPosZ = posZTextBox.Text;
            mClient.connection.Send("posZ=" + mClient.vortexPosZ);
        }

        private void fadeDistTrackBar_Scroll(object sender, EventArgs e)
        {
            TrackBar tBar = (TrackBar)sender;
            float tempInt = tBar.Value*0.1f;
            this.fadeDist.Text = tempInt.ToString();

            if (mClient.connection.valid)
            {
                mClient.connection.Send("fade=" + tBar.Value.ToString());
                //System.Console.Write(tBar.Value.ToString());
            }
        }

        private void statsCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (mClient.connection.valid)
            {
                CheckBox cb = (CheckBox)sender;

                if (cb.Checked)
                {
                    mClient.connection.Send("stats=1");
                }
                else
                {
                    mClient.connection.Send("stats=0");
                }
            }
        }

        private void graphCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (mClient.connection.valid)
            {
                CheckBox cb = (CheckBox)sender;

                if (cb.Checked)
                {
                    mClient.connection.Send("graph=1");
                }
                else
                {
                    mClient.connection.Send("graph=0");
                }
            }
        }

        private void infoButton_Click(object sender, EventArgs e)
        {
            this.statusMessage.Text = "Printing info";
            mClient.connection.Send("info=1");
        }

        private void partBar_Scroll(object sender, EventArgs e)
        {
            TrackBar tBar = (TrackBar)sender;
            float tempInt = tBar.Value * 0.001f;
            this.partLabel.Text = tempInt.ToString();

            if (mClient.connection.valid)
            {
                mClient.connection.Send("part=" + tBar.Value.ToString());
                //System.Console.Write(tBar.Value.ToString());
            }
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            mClient.connection.Send("vorX=" + mClient.vortexX.ToString());
            mClient.connection.Send("vorY=" + mClient.vortexX.ToString());
            mClient.connection.Send("vorZ=" + mClient.vortexX.ToString());

            if (mClient.vortexX.ToString() == mClient.vortexXEnd)
            {
                mClient.vortexXBeg = mClient.vortexXEnd;
            }
            else if(mClient.vortexX.ToString() != mClient.vortexXEnd)
            {
                mClient.vortexX++;
            }
            else if (mClient.vortexY.ToString() == mClient.vortexYEnd)
            {
                mClient.vortexYBeg = mClient.vortexYEnd;
            }
            else if(mClient.vortexY.ToString() != mClient.vortexYEnd)
            {
                mClient.vortexY++;
            }
            if (mClient.vortexZ.ToString() == mClient.vortexZEnd)
            {
                mClient.vortexZBeg = mClient.vortexZEnd;
            }
            else if(mClient.vortexZ.ToString() != mClient.vortexZEnd)
            {
                mClient.vortexZ++;
            }
        }

    }
}
