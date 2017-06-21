using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace Assignment_5.Controllers
{
    public class Artist_vm
    {
    }

    public class ArtistBase
    {
        public ArtistBase()
        {

        }
        [Key]
        public int ArtistId { get; set; }

        public string Name { get; set; }
    }
}