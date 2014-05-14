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
            this.zForce = new System.Windows.Forms.Label();
            this.zLabel = new System.Windows.Forms.Label();
            this.zTrackBar = new System.Windows.Forms.TrackBar();
            this.yForce = new System.Windows.Forms.Label();
            this.yLabel = new System.Windows.Forms.Label();
            this.yTrackBar = new System.Windows.Forms.TrackBar();
            this.xForce = new System.Windows.Forms.Label();
            this.xLabel = new System.Windows.Forms.Label();
            this.xTrackBar = new System.Windows.Forms.TrackBar();
            this.gravityForce = new System.Windows.Forms.Label();
            this.gravity = new System.Windows.Forms.Label();
            this.gravityTrackBar = new System.Windows.Forms.TrackBar();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.statusMessage = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.fieldGroupBox = new System.Windows.Forms.GroupBox();
            this.gravityButton = new System.Windows.Forms.RadioButton();
            this.vortexRadio = new System.Windows.Forms.RadioButton();
            this.windRadio = new System.Windows.Forms.RadioButton();
            this.gravityGroupBox = new System.Windows.Forms.GroupBox();
            this.networkGroupBox.SuspendLayout();
            this.propertiesGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.zTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.yTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.xTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gravityTrackBar)).BeginInit();
            this.statusStrip1.SuspendLayout();
            this.fieldGroupBox.SuspendLayout();
            this.gravityGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // connectButton
            // 
            this.connectButton.Location = new System.Drawing.Point(210, 16);
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
            this.ipTextBox.Size = new System.Drawing.Size(148, 20);
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
            this.networkGroupBox.Size = new System.Drawing.Size(292, 49);
            this.networkGroupBox.TabIndex = 2;
            this.networkGroupBox.TabStop = false;
            this.networkGroupBox.Text = "Network";
            // 
            // adress
            // 
            this.adress.AutoSize = true;
            this.adress.Location = new System.Drawing.Point(8, 19);
            this.adress.Name = "adress";
            this.adress.Size = new System.Drawing.Size(42, 13);
            this.adress.TabIndex = 2;
            this.adress.Text = "Adress:";
            // 
            // propertiesGroupBox
            // 
            this.propertiesGroupBox.Controls.Add(this.zForce);
            this.propertiesGroupBox.Controls.Add(this.zLabel);
            this.propertiesGroupBox.Controls.Add(this.zTrackBar);
            this.propertiesGroupBox.Controls.Add(this.yForce);
            this.propertiesGroupBox.Controls.Add(this.yLabel);
            this.propertiesGroupBox.Controls.Add(this.yTrackBar);
            this.propertiesGroupBox.Controls.Add(this.xForce);
            this.propertiesGroupBox.Controls.Add(this.xLabel);
            this.propertiesGroupBox.Controls.Add(this.xTrackBar);
            this.propertiesGroupBox.Location = new System.Drawing.Point(12, 134);
            this.propertiesGroupBox.Name = "propertiesGroupBox";
            this.propertiesGroupBox.Size = new System.Drawing.Size(292, 139);
            this.propertiesGroupBox.TabIndex = 4;
            this.propertiesGroupBox.TabStop = false;
            this.propertiesGroupBox.Text = "Properties xyz";
            // 
            // zForce
            // 
            this.zForce.AutoSize = true;
            this.zForce.Location = new System.Drawing.Point(262, 104);
            this.zForce.Name = "zForce";
            this.zForce.Size = new System.Drawing.Size(13, 13);
            this.zForce.TabIndex = 8;
            this.zForce.Text = "0";
            // 
            // zLabel
            // 
            this.zLabel.AutoSize = true;
            this.zLabel.Location = new System.Drawing.Point(14, 104);
            this.zLabel.Name = "zLabel";
            this.zLabel.Size = new System.Drawing.Size(14, 13);
            this.zLabel.TabIndex = 7;
            this.zLabel.Text = "Z";
            // 
            // zTrackBar
            // 
            this.zTrackBar.Location = new System.Drawing.Point(56, 95);
            this.zTrackBar.Name = "zTrackBar";
            this.zTrackBar.Size = new System.Drawing.Size(204, 45);
            this.zTrackBar.TabIndex = 6;
            this.zTrackBar.Scroll += new System.EventHandler(this.zTrackBar_Scroll);
            // 
            // yForce
            // 
            this.yForce.AutoSize = true;
            this.yForce.Location = new System.Drawing.Point(262, 62);
            this.yForce.Name = "yForce";
            this.yForce.Size = new System.Drawing.Size(13, 13);
            this.yForce.TabIndex = 5;
            this.yForce.Text = "0";
            // 
            // yLabel
            // 
            this.yLabel.AutoSize = true;
            this.yLabel.Location = new System.Drawing.Point(14, 62);
            this.yLabel.Name = "yLabel";
            this.yLabel.Size = new System.Drawing.Size(14, 13);
            this.yLabel.TabIndex = 4;
            this.yLabel.Text = "Y";
            // 
            // yTrackBar
            // 
            this.yTrackBar.Location = new System.Drawing.Point(56, 53);
            this.yTrackBar.Name = "yTrackBar";
            this.yTrackBar.Size = new System.Drawing.Size(204, 45);
            this.yTrackBar.TabIndex = 3;
            this.yTrackBar.Scroll += new System.EventHandler(this.yTrackBar_Scroll);
            // 
            // xForce
            // 
            this.xForce.AutoSize = true;
            this.xForce.Location = new System.Drawing.Point(262, 24);
            this.xForce.Name = "xForce";
            this.xForce.Size = new System.Drawing.Size(13, 13);
            this.xForce.TabIndex = 2;
            this.xForce.Text = "0";
            // 
            // xLabel
            // 
            this.xLabel.AutoSize = true;
            this.xLabel.Location = new System.Drawing.Point(14, 24);
            this.xLabel.Name = "xLabel";
            this.xLabel.Size = new System.Drawing.Size(14, 13);
            this.xLabel.TabIndex = 1;
            this.xLabel.Text = "X";
            // 
            // xTrackBar
            // 
            this.xTrackBar.Location = new System.Drawing.Point(56, 11);
            this.xTrackBar.Name = "xTrackBar";
            this.xTrackBar.Size = new System.Drawing.Size(204, 45);
            this.xTrackBar.TabIndex = 0;
            this.xTrackBar.Scroll += new System.EventHandler(this.xTrackBar_Scroll);
            // 
            // gravityForce
            // 
            this.gravityForce.AutoSize = true;
            this.gravityForce.Location = new System.Drawing.Point(262, 25);
            this.gravityForce.Name = "gravityForce";
            this.gravityForce.Size = new System.Drawing.Size(13, 13);
            this.gravityForce.TabIndex = 11;
            this.gravityForce.Text = "0";
            // 
            // gravity
            // 
            this.gravity.AutoSize = true;
            this.gravity.Location = new System.Drawing.Point(6, 25);
            this.gravity.Name = "gravity";
            this.gravity.Size = new System.Drawing.Size(40, 13);
            this.gravity.TabIndex = 10;
            this.gravity.Text = "Gravity";
            // 
            // gravityTrackBar
            // 
            this.gravityTrackBar.Location = new System.Drawing.Point(56, 16);
            this.gravityTrackBar.Maximum = 50;
            this.gravityTrackBar.Name = "gravityTrackBar";
            this.gravityTrackBar.Size = new System.Drawing.Size(204, 45);
            this.gravityTrackBar.TabIndex = 9;
            this.gravityTrackBar.Scroll += new System.EventHandler(this.gravityTrackBar_Scroll);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.statusMessage,
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 406);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(319, 22);
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
            // fieldGroupBox
            // 
            this.fieldGroupBox.Controls.Add(this.gravityButton);
            this.fieldGroupBox.Controls.Add(this.vortexRadio);
            this.fieldGroupBox.Controls.Add(this.windRadio);
            this.fieldGroupBox.Location = new System.Drawing.Point(12, 67);
            this.fieldGroupBox.Name = "fieldGroupBox";
            this.fieldGroupBox.Size = new System.Drawing.Size(292, 61);
            this.fieldGroupBox.TabIndex = 6;
            this.fieldGroupBox.TabStop = false;
            this.fieldGroupBox.Text = "Field";
            // 
            // gravityButton
            // 
            this.gravityButton.Appearance = System.Windows.Forms.Appearance.Button;
            this.gravityButton.AutoSize = true;
            this.gravityButton.Location = new System.Drawing.Point(118, 20);
            this.gravityButton.Name = "gravityButton";
            this.gravityButton.Size = new System.Drawing.Size(50, 23);
            this.gravityButton.TabIndex = 2;
            this.gravityButton.TabStop = true;
            this.gravityButton.Text = "Gravity";
            this.gravityButton.UseVisualStyleBackColor = true;
            this.gravityButton.CheckedChanged += new System.EventHandler(this.gravityButton_CheckedChanged);
            // 
            // vortexRadio
            // 
            this.vortexRadio.Appearance = System.Windows.Forms.Appearance.Button;
            this.vortexRadio.AutoSize = true;
            this.vortexRadio.Location = new System.Drawing.Point(65, 20);
            this.vortexRadio.Name = "vortexRadio";
            this.vortexRadio.Size = new System.Drawing.Size(47, 23);
            this.vortexRadio.TabIndex = 1;
            this.vortexRadio.TabStop = true;
            this.vortexRadio.Text = "Vortex";
            this.vortexRadio.UseVisualStyleBackColor = true;
            this.vortexRadio.CheckedChanged += new System.EventHandler(this.vortexRadio_CheckedChanged);
            // 
            // windRadio
            // 
            this.windRadio.Appearance = System.Windows.Forms.Appearance.Button;
            this.windRadio.AutoSize = true;
            this.windRadio.Location = new System.Drawing.Point(17, 20);
            this.windRadio.Name = "windRadio";
            this.windRadio.Size = new System.Drawing.Size(42, 23);
            this.windRadio.TabIndex = 0;
            this.windRadio.TabStop = true;
            this.windRadio.Text = "Wind";
            this.windRadio.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.windRadio.UseVisualStyleBackColor = true;
            this.windRadio.CheckedChanged += new System.EventHandler(this.windRadio_CheckedChanged);
            // 
            // gravityGroupBox
            // 
            this.gravityGroupBox.Controls.Add(this.gravityTrackBar);
            this.gravityGroupBox.Controls.Add(this.gravityForce);
            this.gravityGroupBox.Controls.Add(this.gravity);
            this.gravityGroupBox.Location = new System.Drawing.Point(12, 280);
            this.gravityGroupBox.Name = "gravityGroupBox";
            this.gravityGroupBox.Size = new System.Drawing.Size(292, 70);
            this.gravityGroupBox.TabIndex = 7;
            this.gravityGroupBox.TabStop = false;
            this.gravityGroupBox.Text = "Properties y";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(319, 428);
            this.Controls.Add(this.gravityGroupBox);
            this.Controls.Add(this.fieldGroupBox);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.propertiesGroupBox);
            this.Controls.Add(this.networkGroupBox);
            this.Name = "Form1";
            this.Text = "SnowCozyShietRemote";
            this.networkGroupBox.ResumeLayout(false);
            this.networkGroupBox.PerformLayout();
            this.propertiesGroupBox.ResumeLayout(false);
            this.propertiesGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.zTrackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.yTrackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.xTrackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gravityTrackBar)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.fieldGroupBox.ResumeLayout(false);
            this.fieldGroupBox.PerformLayout();
            this.gravityGroupBox.ResumeLayout(false);
            this.gravityGroupBox.PerformLayout();
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
        private System.Windows.Forms.TrackBar xTrackBar;
        private System.Windows.Forms.Label xLabel;
        private System.Windows.Forms.Label xForce;
        private System.Windows.Forms.TrackBar yTrackBar;
        private System.Windows.Forms.Label yForce;
        private System.Windows.Forms.Label yLabel;
        private System.Windows.Forms.Label zForce;
        private System.Windows.Forms.Label zLabel;
        private System.Windows.Forms.TrackBar zTrackBar;
        private System.Windows.Forms.Label gravityForce;
        private System.Windows.Forms.Label gravity;
        private System.Windows.Forms.TrackBar gravityTrackBar;
        private System.Windows.Forms.GroupBox fieldGroupBox;
        private System.Windows.Forms.RadioButton windRadio;
        private System.Windows.Forms.RadioButton vortexRadio;
        private System.Windows.Forms.GroupBox gravityGroupBox;
        private System.Windows.Forms.RadioButton gravityButton;
    }
}

