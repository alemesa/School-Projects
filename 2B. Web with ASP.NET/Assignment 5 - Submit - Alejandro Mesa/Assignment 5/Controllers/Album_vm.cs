using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace Assignment_5.Controllers
{
    public class Album_vm
    {
    }

    public class AlbumBase
    {
        public AlbumBase()
        {

        }
        [Key]
        public int AlbumId { get; set; }

        public string Title { get; set; }

        public int ArtistId { get; set; }
    }
}