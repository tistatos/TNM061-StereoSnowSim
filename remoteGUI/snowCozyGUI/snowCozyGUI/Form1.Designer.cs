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
            this.forceGroupBox = new System.Windows.Forms.GroupBox();
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
            this.propertiesGroupBox = new System.Windows.Forms.GroupBox();
            this.posZTextBox = new System.Windows.Forms.TextBox();
            this.posXTextBox = new System.Windows.Forms.TextBox();
            this.zPosLabel = new System.Windows.Forms.Label();
            this.xPosLabel = new System.Windows.Forms.Label();
            this.radiusLabel = new System.Windows.Forms.Label();
            this.radiusTextBox = new System.Windows.Forms.TextBox();
            this.pausButton = new System.Windows.Forms.Button();
            this.programGroupBox = new System.Windows.Forms.GroupBox();
            this.infoButton = new System.Windows.Forms.Button();
            this.graphCheckBox = new System.Windows.Forms.CheckBox();
            this.statsCheckBox = new System.Windows.Forms.CheckBox();
            this.fadeDistTrackBar = new System.Windows.Forms.TrackBar();
            this.fadeDistGroupBox = new System.Windows.Forms.GroupBox();
            this.fadeDist = new System.Windows.Forms.Label();
            this.partGroupBox = new System.Windows.Forms.GroupBox();
            this.partBar = new System.Windows.Forms.TrackBar();
            this.partLabel = new System.Windows.Forms.Label();
            this.networkGroupBox.SuspendLayout();
            this.forceGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.zTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.yTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.xTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gravityTrackBar)).BeginInit();
            this.statusStrip1.SuspendLayout();
            this.fieldGroupBox.SuspendLayout();
            this.gravityGroupBox.SuspendLayout();
            this.propertiesGroupBox.SuspendLayout();
            this.programGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fadeDistTrackBar)).BeginInit();
            this.fadeDistGroupBox.SuspendLayout();
            this.partGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.partBar)).BeginInit();
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
            this.networkGroupBox.BackColor = System.Drawing.SystemColors.Control;
            this.networkGroupBox.Controls.Add(this.adress);
            this.networkGroupBox.Controls.Add(this.ipTextBox);
            this.networkGroupBox.Controls.Add(this.connectButton);
            this.networkGroupBox.Location = new System.Drawing.Point(12, 0);
            this.networkGroupBox.Name = "networkGroupBox";
            this.networkGroupBox.Size = new System.Drawing.Size(292, 61);
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
            // forceGroupBox
            // 
            this.forceGroupBox.Controls.Add(this.zForce);
            this.forceGroupBox.Controls.Add(this.zLabel);
            this.forceGroupBox.Controls.Add(this.zTrackBar);
            this.forceGroupBox.Controls.Add(this.yForce);
            this.forceGroupBox.Controls.Add(this.yLabel);
            this.forceGroupBox.Controls.Add(this.yTrackBar);
            this.forceGroupBox.Controls.Add(this.xForce);
            this.forceGroupBox.Controls.Add(this.xLabel);
            this.forceGroupBox.Controls.Add(this.xTrackBar);
            this.forceGroupBox.Location = new System.Drawing.Point(326, 48);
            this.forceGroupBox.Name = "forceGroupBox";
            this.forceGroupBox.Size = new System.Drawing.Size(292, 151);
            this.forceGroupBox.TabIndex = 4;
            this.forceGroupBox.TabStop = false;
            this.forceGroupBox.Text = "Force";
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
            this.zTrackBar.Minimum = -10;
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
            this.yTrackBar.Minimum = -10;
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
            this.xTrackBar.Minimum = -10;
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
            this.gravityForce.Size = new System.Drawing.Size(19, 13);
            this.gravityForce.TabIndex = 11;
            this.gravityForce.Text = "10";
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
            this.gravityTrackBar.Value = 10;
            this.gravityTrackBar.Scroll += new System.EventHandler(this.gravityTrackBar_Scroll);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.statusMessage,
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 356);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(640, 22);
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
            this.fieldGroupBox.Location = new System.Drawing.Point(12, 283);
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
            this.gravityGroupBox.Location = new System.Drawing.Point(326, 283);
            this.gravityGroupBox.Name = "gravityGroupBox";
            this.gravityGroupBox.Size = new System.Drawing.Size(292, 70);
            this.gravityGroupBox.TabIndex = 7;
            this.gravityGroupBox.TabStop = false;
            this.gravityGroupBox.Text = "Acceleration";
            // 
            // propertiesGroupBox
            // 
            this.propertiesGroupBox.Controls.Add(this.posZTextBox);
            this.propertiesGroupBox.Controls.Add(this.posXTextBox);
            this.propertiesGroupBox.Controls.Add(this.zPosLabel);
            this.propertiesGroupBox.Controls.Add(this.xPosLabel);
            this.propertiesGroupBox.Controls.Add(this.radiusLabel);
            this.propertiesGroupBox.Controls.Add(this.radiusTextBox);
            this.propertiesGroupBox.Location = new System.Drawing.Point(326, 209);
            this.propertiesGroupBox.Name = "propertiesGroupBox";
            this.propertiesGroupBox.Size = new System.Drawing.Size(292, 68);
            this.propertiesGroupBox.TabIndex = 8;
            this.propertiesGroupBox.TabStop = false;
            this.propertiesGroupBox.Text = "Properties";
            // 
            // posZTextBox
            // 
            this.posZTextBox.Location = new System.Drawing.Point(244, 32);
            this.posZTextBox.Name = "posZTextBox";
            this.posZTextBox.Size = new System.Drawing.Size(42, 20);
            this.posZTextBox.TabIndex = 6;
            this.posZTextBox.TextChanged += new System.EventHandler(this.posZTextBox_TextChanged);
            // 
            // posXTextBox
            // 
            this.posXTextBox.Location = new System.Drawing.Point(150, 32);
            this.posXTextBox.Name = "posXTextBox";
            this.posXTextBox.Size = new System.Drawing.Size(42, 20);
            this.posXTextBox.TabIndex = 5;
            this.posXTextBox.TextChanged += new System.EventHandler(this.posXTextBox_TextChanged);
            // 
            // zPosLabel
            // 
            this.zPosLabel.AutoSize = true;
            this.zPosLabel.Location = new System.Drawing.Point(203, 35);
            this.zPosLabel.Name = "zPosLabel";
            this.zPosLabel.Size = new System.Drawing.Size(35, 13);
            this.zPosLabel.TabIndex = 4;
            this.zPosLabel.Text = "Pos Z";
            // 
            // xPosLabel
            // 
            this.xPosLabel.AutoSize = true;
            this.xPosLabel.Location = new System.Drawing.Point(109, 35);
            this.xPosLabel.Name = "xPosLabel";
            this.xPosLabel.Size = new System.Drawing.Size(35, 13);
            this.xPosLabel.TabIndex = 3;
            this.xPosLabel.Text = "Pos X";
            // 
            // radiusLabel
            // 
            this.radiusLabel.AutoSize = true;
            this.radiusLabel.Location = new System.Drawing.Point(6, 35);
            this.radiusLabel.Name = "radiusLabel";
            this.radiusLabel.Size = new System.Drawing.Size(40, 13);
            this.radiusLabel.TabIndex = 1;
            this.radiusLabel.Text = "Radius";
            // 
            // radiusTextBox
            // 
            this.radiusTextBox.Location = new System.Drawing.Point(52, 32);
            this.radiusTextBox.Name = "radiusTextBox";
            this.radiusTextBox.Size = new System.Drawing.Size(40, 20);
            this.radiusTextBox.TabIndex = 0;
            this.radiusTextBox.TextChanged += new System.EventHandler(this.radiusTextBox_TextChanged);
            // 
            // pausButton
            // 
            this.pausButton.Location = new System.Drawing.Point(234, 19);
            this.pausButton.Name = "pausButton";
            this.pausButton.Size = new System.Drawing.Size(48, 23);
            this.pausButton.TabIndex = 9;
            this.pausButton.Text = "Pause";
            this.pausButton.UseVisualStyleBackColor = true;
            this.pausButton.Click += new System.EventHandler(this.pausButton_Click);
            // 
            // programGroupBox
            // 
            this.programGroupBox.Controls.Add(this.infoButton);
            this.programGroupBox.Controls.Add(this.graphCheckBox);
            this.programGroupBox.Controls.Add(this.statsCheckBox);
            this.programGroupBox.Controls.Add(this.pausButton);
            this.programGroupBox.Location = new System.Drawing.Point(12, 67);
            this.programGroupBox.Name = "programGroupBox";
            this.programGroupBox.Size = new System.Drawing.Size(292, 55);
            this.programGroupBox.TabIndex = 10;
            this.programGroupBox.TabStop = false;
            this.programGroupBox.Text = "Program";
            // 
            // infoButton
            // 
            this.infoButton.Location = new System.Drawing.Point(155, 19);
            this.infoButton.Name = "infoButton";
            this.infoButton.Size = new System.Drawing.Size(60, 23);
            this.infoButton.TabIndex = 12;
            this.infoButton.Text = "Print info";
            this.infoButton.UseVisualStyleBackColor = true;
            this.infoButton.Click += new System.EventHandler(this.infoButton_Click);
            // 
            // graphCheckBox
            // 
            this.graphCheckBox.AutoSize = true;
            this.graphCheckBox.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.graphCheckBox.Location = new System.Drawing.Point(65, 23);
            this.graphCheckBox.Name = "graphCheckBox";
            this.graphCheckBox.Size = new System.Drawing.Size(55, 17);
            this.graphCheckBox.TabIndex = 11;
            this.graphCheckBox.Text = "Graph";
            this.graphCheckBox.UseVisualStyleBackColor = true;
            this.graphCheckBox.CheckedChanged += new System.EventHandler(this.graphCheckBox_CheckedChanged);
            // 
            // statsCheckBox
            // 
            this.statsCheckBox.AutoSize = true;
            this.statsCheckBox.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.statsCheckBox.Location = new System.Drawing.Point(6, 23);
            this.statsCheckBox.Name = "statsCheckBox";
            this.statsCheckBox.Size = new System.Drawing.Size(50, 17);
            this.statsCheckBox.TabIndex = 10;
            this.statsCheckBox.Text = "Stats";
            this.statsCheckBox.UseVisualStyleBackColor = true;
            this.statsCheckBox.CheckedChanged += new System.EventHandler(this.statsCheckBox_CheckedChanged);
            // 
            // fadeDistTrackBar
            // 
            this.fadeDistTrackBar.BackColor = System.Drawing.SystemColors.Control;
            this.fadeDistTrackBar.Location = new System.Drawing.Point(11, 19);
            this.fadeDistTrackBar.Maximum = 100;
            this.fadeDistTrackBar.Minimum = 1;
            this.fadeDistTrackBar.Name = "fadeDistTrackBar";
            this.fadeDistTrackBar.Size = new System.Drawing.Size(243, 45);
            this.fadeDistTrackBar.TabIndex = 11;
            this.fadeDistTrackBar.Value = 40;
            this.fadeDistTrackBar.Scroll += new System.EventHandler(this.fadeDistTrackBar_Scroll);
            // 
            // fadeDistGroupBox
            // 
            this.fadeDistGroupBox.Controls.Add(this.fadeDist);
            this.fadeDistGroupBox.Controls.Add(this.fadeDistTrackBar);
            this.fadeDistGroupBox.Location = new System.Drawing.Point(12, 135);
            this.fadeDistGroupBox.Name = "fadeDistGroupBox";
            this.fadeDistGroupBox.Size = new System.Drawing.Size(292, 66);
            this.fadeDistGroupBox.TabIndex = 11;
            this.fadeDistGroupBox.TabStop = false;
            this.fadeDistGroupBox.Text = "Fade Distance";
            // 
            // fadeDist
            // 
            this.fadeDist.AutoSize = true;
            this.fadeDist.Location = new System.Drawing.Point(260, 34);
            this.fadeDist.Name = "fadeDist";
            this.fadeDist.Size = new System.Drawing.Size(22, 13);
            this.fadeDist.TabIndex = 12;
            this.fadeDist.Text = "4.0";
            // 
            // partGroupBox
            // 
            this.partGroupBox.Controls.Add(this.partLabel);
            this.partGroupBox.Controls.Add(this.partBar);
            this.partGroupBox.Location = new System.Drawing.Point(13, 209);
            this.partGroupBox.Name = "partGroupBox";
            this.partGroupBox.Size = new System.Drawing.Size(291, 68);
            this.partGroupBox.TabIndex = 12;
            this.partGroupBox.TabStop = false;
            this.partGroupBox.Text = "Particle size";
            // 
            // partBar
            // 
            this.partBar.Location = new System.Drawing.Point(10, 19);
            this.partBar.Maximum = 1000;
            this.partBar.Name = "partBar";
            this.partBar.Size = new System.Drawing.Size(243, 45);
            this.partBar.TabIndex = 0;
            this.partBar.Value = 40;
            this.partBar.Scroll += new System.EventHandler(this.partBar_Scroll);
            // 
            // partLabel
            // 
            this.partLabel.AutoSize = true;
            this.partLabel.Location = new System.Drawing.Point(251, 35);
            this.partLabel.Name = "partLabel";
            this.partLabel.Size = new System.Drawing.Size(28, 13);
            this.partLabel.TabIndex = 1;
            this.partLabel.Text = "0.04";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(640, 378);
            this.Controls.Add(this.partGroupBox);
            this.Controls.Add(this.fadeDistGroupBox);
            this.Controls.Add(this.programGroupBox);
            this.Controls.Add(this.propertiesGroupBox);
            this.Controls.Add(this.gravityGroupBox);
            this.Controls.Add(this.fieldGroupBox);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.forceGroupBox);
            this.Controls.Add(this.networkGroupBox);
            this.Name = "Form1";
            this.Text = "SnowCozyShietRemote";
            this.networkGroupBox.ResumeLayout(false);
            this.networkGroupBox.PerformLayout();
            this.forceGroupBox.ResumeLayout(false);
            this.forceGroupBox.PerformLayout();
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
            this.propertiesGroupBox.ResumeLayout(false);
            this.propertiesGroupBox.PerformLayout();
            this.programGroupBox.ResumeLayout(false);
            this.programGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fadeDistTrackBar)).EndInit();
            this.fadeDistGroupBox.ResumeLayout(false);
            this.fadeDistGroupBox.PerformLayout();
            this.partGroupBox.ResumeLayout(false);
            this.partGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.partBar)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button connectButton;
        private System.Windows.Forms.TextBox ipTextBox;
        private System.Windows.Forms.GroupBox networkGroupBox;
        private System.Windows.Forms.Label adress;
        private System.Windows.Forms.GroupBox forceGroupBox;
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
        private System.Windows.Forms.GroupBox propertiesGroupBox;
        private System.Windows.Forms.TextBox posZTextBox;
        private System.Windows.Forms.TextBox posXTextBox;
        private System.Windows.Forms.Label zPosLabel;
        private System.Windows.Forms.Label xPosLabel;
        private System.Windows.Forms.Label radiusLabel;
        private System.Windows.Forms.TextBox radiusTextBox;
        private System.Windows.Forms.Button pausButton;
        private System.Windows.Forms.GroupBox programGroupBox;
        private System.Windows.Forms.CheckBox graphCheckBox;
        private System.Windows.Forms.CheckBox statsCheckBox;
        private System.Windows.Forms.TrackBar fadeDistTrackBar;
        private System.Windows.Forms.GroupBox fadeDistGroupBox;
        private System.Windows.Forms.Label fadeDist;
        private System.Windows.Forms.Button infoButton;
        private System.Windows.Forms.GroupBox partGroupBox;
        private System.Windows.Forms.Label partLabel;
        private System.Windows.Forms.TrackBar partBar;
    }
}

