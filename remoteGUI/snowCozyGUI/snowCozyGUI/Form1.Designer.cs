namespace snowCozyGUI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.connectButton = new System.Windows.Forms.Button();
            this.ipTextBox = new System.Windows.Forms.TextBox();
            this.networkGroupBox = new System.Windows.Forms.GroupBox();
            this.adress = new System.Windows.Forms.Label();
            this.propertiesGroupBox = new System.Windows.Forms.GroupBox();
            this.windYTrackBar = new System.Windows.Forms.TrackBar();
            this.windXForce = new System.Windows.Forms.Label();
            this.windX = new System.Windows.Forms.Label();
            this.windXTrackBar = new System.Windows.Forms.TrackBar();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.statusMessage = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.windY = new System.Windows.Forms.Label();
            this.windYForce = new System.Windows.Forms.Label();
            this.windZTrackBar = new System.Windows.Forms.TrackBar();
            this.windZ = new System.Windows.Forms.Label();
            this.windZForce = new System.Windows.Forms.Label();
            this.networkGroupBox.SuspendLayout();
            this.propertiesGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.windYTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.windXTrackBar)).BeginInit();
            this.statusStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.windZTrackBar)).BeginInit();
            this.SuspendLayout();
            // 
            // connectButton
            // 
            this.connectButton.Location = new System.Drawing.Point(199, 15);
            this.connectButton.Name = "connectButton";
            this.connectButton.Size = new System.Drawing.Size(76, 20);
            this.connectButton.TabIndex = 0;
            this.connectButton.Text = "Connect";
            this.connectButton.UseVisualStyleBackColor = true;
            this.connectButton.Click += new System.EventHandler(this.connectButton_Click);
            // 
            // ipTextBox
            // 
            this.ipTextBox.Location = new System.Drawing.Point(56, 16);
            this.ipTextBox.Name = "ipTextBox";
            this.ipTextBox.Size = new System.Drawing.Size(137, 20);
            this.ipTextBox.TabIndex = 1;
            this.ipTextBox.Text = "127.0.0.1";
            // 
            // networkGroupBox
            // 
            this.networkGroupBox.Controls.Add(this.adress);
            this.networkGroupBox.Controls.Add(this.ipTextBox);
            this.networkGroupBox.Controls.Add(this.connectButton);
            this.networkGroupBox.Location = new System.Drawing.Point(12, 12);
            this.networkGroupBox.Name = "networkGroupBox";
            this.networkGroupBox.Size = new System.Drawing.Size(281, 49);
            this.networkGroupBox.TabIndex = 2;
            this.networkGroupBox.TabStop = false;
            this.networkGroupBox.Text = "Network";
            this.networkGroupBox.Enter += new System.EventHandler(this.networkGroupBox_Enter);
            // 
            // adress
            // 
            this.adress.AutoSize = true;
            this.adress.Location = new System.Drawing.Point(8, 19);
            this.adress.Name = "adress";
            this.adress.Size = new System.Drawing.Size(42, 13);
            this.adress.TabIndex = 2;
            this.adress.Text = "Adress:";
            this.adress.Click += new System.EventHandler(this.adress_Click);
            // 
            // propertiesGroupBox
            // 
            this.propertiesGroupBox.Controls.Add(this.windZForce);
            this.propertiesGroupBox.Controls.Add(this.windZ);
            this.propertiesGroupBox.Controls.Add(this.windZTrackBar);
            this.propertiesGroupBox.Controls.Add(this.windYForce);
            this.propertiesGroupBox.Controls.Add(this.windY);
            this.propertiesGroupBox.Controls.Add(this.windYTrackBar);
            this.propertiesGroupBox.Controls.Add(this.windXForce);
            this.propertiesGroupBox.Controls.Add(this.windX);
            this.propertiesGroupBox.Controls.Add(this.windXTrackBar);
            this.propertiesGroupBox.Location = new System.Drawing.Point(12, 67);
            this.propertiesGroupBox.Name = "propertiesGroupBox";
            this.propertiesGroupBox.Size = new System.Drawing.Size(281, 336);
            this.propertiesGroupBox.TabIndex = 4;
            this.propertiesGroupBox.TabStop = false;
            this.propertiesGroupBox.Text = "Properties";
            // 
            // windYTrackBar
            // 
            this.windYTrackBar.Location = new System.Drawing.Point(56, 62);
            this.windYTrackBar.Name = "windYTrackBar";
            this.windYTrackBar.Size = new System.Drawing.Size(204, 45);
            this.windYTrackBar.TabIndex = 3;
            this.windYTrackBar.Scroll += new System.EventHandler(this.windYTrackBar_Scroll);
            // 
            // windXForce
            // 
            this.windXForce.AutoSize = true;
            this.windXForce.Location = new System.Drawing.Point(262, 24);
            this.windXForce.Name = "windXForce";
            this.windXForce.Size = new System.Drawing.Size(13, 13);
            this.windXForce.TabIndex = 2;
            this.windXForce.Text = "0";
            // 
            // windX
            // 
            this.windX.AutoSize = true;
            this.windX.Location = new System.Drawing.Point(11, 24);
            this.windX.Name = "windX";
            this.windX.Size = new System.Drawing.Size(39, 13);
            this.windX.TabIndex = 1;
            this.windX.Text = "WindX";
            // 
            // windXTrackBar
            // 
            this.windXTrackBar.Location = new System.Drawing.Point(56, 24);
            this.windXTrackBar.Name = "windXTrackBar";
            this.windXTrackBar.Size = new System.Drawing.Size(204, 45);
            this.windXTrackBar.TabIndex = 0;
            this.windXTrackBar.Scroll += new System.EventHandler(this.windXTrackBar_Scroll);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.statusMessage,
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 406);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(305, 22);
            this.statusStrip1.TabIndex = 5;
            // 
            // statusMessage
            // 
            this.statusMessage.Name = "statusMessage";
            this.statusMessage.Size = new System.Drawing.Size(0, 17);
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(0, 17);
            // 
            // windY
            // 
            this.windY.AutoSize = true;
            this.windY.Location = new System.Drawing.Point(11, 62);
            this.windY.Name = "windY";
            this.windY.Size = new System.Drawing.Size(39, 13);
            this.windY.TabIndex = 4;
            this.windY.Text = "WindY";
            // 
            // windYForce
            // 
            this.windYForce.AutoSize = true;
            this.windYForce.Location = new System.Drawing.Point(262, 62);
            this.windYForce.Name = "windYForce";
            this.windYForce.Size = new System.Drawing.Size(13, 13);
            this.windYForce.TabIndex = 5;
            this.windYForce.Text = "0";
            // 
            // windZTrackBar
            // 
            this.windZTrackBar.Location = new System.Drawing.Point(56, 104);
            this.windZTrackBar.Name = "windZTrackBar";
            this.windZTrackBar.Size = new System.Drawing.Size(204, 45);
            this.windZTrackBar.TabIndex = 6;
            this.windZTrackBar.Scroll += new System.EventHandler(this.windZTrackBar_Scroll);
            // 
            // windZ
            // 
            this.windZ.AutoSize = true;
            this.windZ.Location = new System.Drawing.Point(11, 104);
            this.windZ.Name = "windZ";
            this.windZ.Size = new System.Drawing.Size(39, 13);
            this.windZ.TabIndex = 7;
            this.windZ.Text = "WindZ";
            // 
            // windZForce
            // 
            this.windZForce.AutoSize = true;
            this.windZForce.Location = new System.Drawing.Point(262, 104);
            this.windZForce.Name = "windZForce";
            this.windZForce.Size = new System.Drawing.Size(13, 13);
            this.windZForce.TabIndex = 8;
            this.windZForce.Text = "0";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(305, 428);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.propertiesGroupBox);
            this.Controls.Add(this.networkGroupBox);
            this.Name = "Form1";
            this.Text = "SnowCozyShietRemote";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.networkGroupBox.ResumeLayout(false);
            this.networkGroupBox.PerformLayout();
            this.propertiesGroupBox.ResumeLayout(false);
            this.propertiesGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.windYTrackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.windXTrackBar)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.windZTrackBar)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button connectButton;
        private System.Windows.Forms.TextBox ipTextBox;
        private System.Windows.Forms.GroupBox networkGroupBox;
        private System.Windows.Forms.Label adress;
        private System.Windows.Forms.GroupBox propertiesGroupBox;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel statusMessage;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.TrackBar windXTrackBar;
        private System.Windows.Forms.Label windX;
        private System.Windows.Forms.Label windXForce;
        private System.Windows.Forms.TrackBar windYTrackBar;
        private System.Windows.Forms.Label windYForce;
        private System.Windows.Forms.Label windY;
        private System.Windows.Forms.Label windZForce;
        private System.Windows.Forms.Label windZ;
        private System.Windows.Forms.TrackBar windZTrackBar;
    }
}

