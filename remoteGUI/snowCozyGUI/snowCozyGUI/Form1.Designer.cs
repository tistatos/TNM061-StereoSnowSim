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
            this.windForce = new System.Windows.Forms.Label();
            this.Wind = new System.Windows.Forms.Label();
            this.windTrackBar = new System.Windows.Forms.TrackBar();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.statusMessage = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.networkGroupBox.SuspendLayout();
            this.propertiesGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.windTrackBar)).BeginInit();
            this.statusStrip1.SuspendLayout();
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
            this.ipTextBox.Size = new System.Drawing.Size(126, 20);
            this.ipTextBox.TabIndex = 1;
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
            this.propertiesGroupBox.Controls.Add(this.windForce);
            this.propertiesGroupBox.Controls.Add(this.Wind);
            this.propertiesGroupBox.Controls.Add(this.windTrackBar);
            this.propertiesGroupBox.Location = new System.Drawing.Point(12, 67);
            this.propertiesGroupBox.Name = "propertiesGroupBox";
            this.propertiesGroupBox.Size = new System.Drawing.Size(260, 170);
            this.propertiesGroupBox.TabIndex = 4;
            this.propertiesGroupBox.TabStop = false;
            this.propertiesGroupBox.Text = "Properties";
            // 
            // windForce
            // 
            this.windForce.AutoSize = true;
            this.windForce.Location = new System.Drawing.Point(21, 37);
            this.windForce.Name = "windForce";
            this.windForce.Size = new System.Drawing.Size(13, 13);
            this.windForce.TabIndex = 2;
            this.windForce.Text = "0";
            // 
            // Wind
            // 
            this.Wind.AutoSize = true;
            this.Wind.Location = new System.Drawing.Point(8, 19);
            this.Wind.Name = "Wind";
            this.Wind.Size = new System.Drawing.Size(32, 13);
            this.Wind.TabIndex = 1;
            this.Wind.Text = "Wind";
            // 
            // windTrackBar
            // 
            this.windTrackBar.Location = new System.Drawing.Point(46, 19);
            this.windTrackBar.Name = "windTrackBar";
            this.windTrackBar.Size = new System.Drawing.Size(208, 45);
            this.windTrackBar.TabIndex = 0;
            this.windTrackBar.Scroll += new System.EventHandler(this.windTrackBar_Scroll);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.statusMessage,
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 240);
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
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(305, 262);
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
            ((System.ComponentModel.ISupportInitialize)(this.windTrackBar)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
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
        private System.Windows.Forms.TrackBar windTrackBar;
        private System.Windows.Forms.Label Wind;
        private System.Windows.Forms.Label windForce;
    }
}

